#pragma once
#include "CBrick.h"
#include <vector>
#include <fstream>
using namespace std;
class CEditor
{
public:
	CEditor();
	~CEditor();
public:
	CBrick * Brick;
	vector <CBrick*> Bricks;
public:
	void fn_submitBrick(CBrick *brick);
	void fn_saveLevel(string fileName);
public:
	// Variables archivo}
	string m_fileName = "Level";
	int m_numFile;


};

