#include "stdafx.h"
#include "CBrick.h"

CBrick::CBrick()
{

}

CBrick::CBrick(CDC* pDC)
{
	HANDLE hBitmap = LoadImage(0, TEXT("brick.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp;
	bmp.Attach(reinterpret_cast<HBITMAP>(hBitmap));
	bmDC.CreateCompatibleDC(pDC);
	m_BrickSizes = bmp.GetBitmap(&Bitsizebrick);
	m_BitBrickHeight = Bitsizebrick.bmHeight;
	m_BitBrickWidth = Bitsizebrick.bmWidth;
	CBitmap* oldBMP = bmDC.SelectObject(&bmp);
}


CBrick::~CBrick()
{
}

void CBrick::fn_paintBrick(CDC* pDC, int posX, int posY)
{
	pDC->BitBlt(posX, posY, m_BitBrickWidth, m_BitBrickHeight, &bmDC, 0, 0, SRCCOPY);
}

void CBrick::fn_Collider(int BallPosY, int BallPosX, int &BallDirY, int &BallDirX, int BitBallH,int BrickPosX,int BrickPosY, int& res)
{

	// Stop in left
	if (m_xWidth1 < m_leftSideBar)
	{
		m_xWidth1 = m_leftSideBar;
		m_xWidth2 = m_xWidth1 + 100;
	}
	// Stop in right
	else if (m_xWidth2 > m_rightSideBar)	
	{
		m_xWidth2 = m_rightSideBar;
		m_xWidth1 = m_xWidth2 - 100;
	}

	if (BallPosY + BitBallH > BrickPosY && BallPosY < (BrickPosY + m_BitBrickHeight))
	{
		// Condiciones Mouse Middle
		if (BallPosX + BitBallH > BrickPosX + 5 && BallPosX < BrickPosX + m_BitBrickWidth - 5) // m_BitBallHeight / 2 = 32
		{
			if (BallDirY == -5)
			{
				BallDirY = 5;
				

			}
			else
			{
				BallDirY = -5;
				res = -1;
			}
			res = -1;
			//Ball.DirX = 5;
		}
	}
	if (BallPosX + BitBallH > BrickPosX && BallPosX < BrickPosX + m_BitBrickWidth)
	{
		// Condiciones Mouse Middle
		if (BallPosY + BitBallH > BrickPosY + 5 && BallPosY < (BrickPosY + m_BitBrickHeight - 5)) // m_BitBallHeight / 2 = 32
		{
			if (BallDirX == -5)
			{
				BallDirX = 5;
				res = -1;
			}
			else
			{
				BallDirX = -5;
				res = -1;
			}
			res = -1;
			//Ball.DirX = 5;
		}
	}
}

