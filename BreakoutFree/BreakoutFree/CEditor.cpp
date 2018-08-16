#include "stdafx.h"
#include "CEditor.h"
#include "afxwin.h"

CEditor::CEditor()
{
}


CEditor::~CEditor()
{
}

void CEditor::fn_submitBrick(CBrick *brick)
{
	Bricks.push_back(brick);
}
void CEditor::fn_saveLevel(string LevelName)
{
	fstream *NewLevel = new fstream(LevelName + ".txt", ios::out);
	if (NewLevel->fail())
	{
		exit(1);
	}
	for (int i = 0; i < Bricks.size(); i++)
	{
		(*NewLevel) << Bricks[i]->m_PosX << " " << Bricks[i]->m_PosY << " " << Bricks[i]->m_Resistance << '\n';
	}
	NewLevel->close();
	if (NewLevel) // Revisa que Nueva_Partida no sea nulo(vacio). REvisa que el puntero
	{
		AfxMessageBox( _T("/* C008: (!) RELEASED MEMORY */"));
		delete(NewLevel);
	}
	else
	{
		AfxMessageBox(_T("/* C009: (!) MEMORYLEAK PROBLEM */"));
	}
	AfxMessageBox(_T("C004: (!) SE HA GUARDADO EXITOSAMENTE LA PARTIDA"));
}
