#pragma once
class CBrick
{
public:
	CBrick();
	CBrick(CDC* pDC);
	~CBrick();
public:
	void fn_paintBrick(CDC* pDC, int posX, int posY);
	void fn_Collider(int BallPosY, int BallPosX, int &BallDirY, int &BallDirX, int BitBallH, int BrickPosX, int BrickPosY, int& res);
	
public:
	int m_xWidth1;
	int m_xWidth2;
	int m_leftSideBar;
	int m_rightSideBar;
	int m_bottomSideBar;

	int m_PosX = 100;
	int m_PosY = 116;
	int m_DirX = 5;
	int m_DirY = 5;
	int m_Resistance = 1;
	// Size of the bitmap "Ball / Dummie"

	int m_ballSizeX;
	int m_BallSizeY;

	bool m_exist = true;
	//Brick
	CDC bmDC;
	BITMAP Bitsizebrick;
	int m_BrickSizes;
	int m_BitBrickWidth;
	int m_BitBrickHeight;
};

