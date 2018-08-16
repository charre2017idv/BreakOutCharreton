#pragma once
#include <vector>
#include <fstream>
#include "CBrick.h"
using namespace std;
class CScene
{
public:
	CScene();
	~CScene();
public:
	
public:
	void fn_frame(CDC* pDC, RECT rect);
	void fn_loadLevel(string nameFile);
	void fn_Ball();

public:
	string m_lector = "Something";
	
	int m_positionData;
	int m_brickCounter;
public:
	vector <CBrick*> BricksPositions;
};

