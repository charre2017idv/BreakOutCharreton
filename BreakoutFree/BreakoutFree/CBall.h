#pragma once
#include "CBar.h"
class CBall
{
public:
	CBall();
	CBall(CDC* pDC);
	~CBall();
public:
	//CBar Bar;
public:
	void fn_paintBall(CDC* pDC);
	void fn_movment(RECT rect, int posBarX);
	void fn_collider(RECT rect, int barwith, int barwith2);
public:
	CDC bmDC;
	BITMAP Bitsize;
	int m_BallSizes;
	int m_BitBallWidth;
	int m_BitBallHeight;

	// COORDINATES
	int PosX = 0; // Position X (Where the ball is located in axis X)
	int PosY = 0; // Position X (Where the ball is located in axis X)
	int DirX = 5; // Direction X (where the ball is going to move in axis X)
	int DirY = 5; // Direction Y (where the ball is going to move in axis Y)

	// Size of the window 
	long m_bottom;
	long m_right;
};

