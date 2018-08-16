#include "stdafx.h"
#include "CScene.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

CScene::CScene()
{
}


CScene::~CScene()
{
}

void CScene::fn_frame(CDC* pDC, RECT rect)
{
	pDC->Rectangle(0, 0, rect.right + 2, rect.bottom);
}


void CScene::fn_loadLevel(string nameFile)
{
	ifstream *loadGame = new ifstream(nameFile, ios::in);
	if (loadGame->fail())
	{
		AfxMessageBox(_T("C0005: (!) Error de Carga del archivo."));
	}
	//if (BricksPositions.size() <= 1)
	//{
	//	AfxMessageBox(_T("C0006: (!) Error de Carga del archivo: No cuenta con un archivo al cual cargar."));
	//	exit(1);
	//}
	getline(*loadGame, m_lector);
	while (m_lector != "\0")
	{
		int i=0;
		string m_BrickPosX;
		string m_BrickPosY;
		string m_BrickRes;
		
		while(m_lector[i] !=' ')
		{
			m_BrickPosX += m_lector[i];
			i++;
		}
		i++;
		while (m_lector[i] != ' ')
		{
			m_BrickPosY += m_lector[i];
			i++;
		}
		i++;
		while (i<m_lector.size())
		{
			m_BrickRes += m_lector[i];
			i++;
		}
		CBrick *Brick = new CBrick();
		Brick->m_PosX = atoi(m_BrickPosX.c_str());
		Brick->m_PosY = atoi(m_BrickPosY.c_str());
		Brick->m_Resistance = atoi(m_BrickRes.c_str());
		BricksPositions.push_back(Brick);
		getline(*loadGame, m_lector);
	}

	loadGame->close();
	if (loadGame)
	{
		AfxMessageBox(_T("C008: (!) RELEASED MEMORY"));
		delete(loadGame);
	}
	else
	{
		AfxMessageBox(_T("C009: (!) MEMORYLEAK PROBLEM"));
	}
}
