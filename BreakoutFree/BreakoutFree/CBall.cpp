#include "stdafx.h"
#include "CBall.h"

CBall::CBall() 
{

}
CBall::CBall(CDC* pDC)
{
	HANDLE hBitmap = LoadImage(0, TEXT("Dummie.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp;
	bmp.Attach(reinterpret_cast<HBITMAP>(hBitmap));
	bmDC.CreateCompatibleDC(pDC);
	m_BallSizes = bmp.GetBitmap(&Bitsize);
	m_BitBallHeight = Bitsize.bmHeight;
	m_BitBallWidth = Bitsize.bmWidth;
	CBitmap* oldBMP = bmDC.SelectObject(&bmp);
}


CBall::~CBall()
{
}

void CBall::fn_paintBall(CDC* pDC)
{
	pDC->BitBlt(PosX, PosY, m_BitBallWidth, m_BitBallHeight, &bmDC, 0, 0, SRCCOPY);
}

void CBall::fn_movment(RECT rect, int posBarX)
{
	/* En el eje Y */
	if (PosY < 0)
	{ // Si posY es igual a 0 entonces la direccion sera 5
		DirY = 5;
	}
	/* En el eje X */
	if (PosX < 0)
	{
		DirX = 5;
	}
	if (PosX > rect.right - 64)
	{
		DirX = -5;
	}
	/* Muerte */
	if (PosY > rect.bottom - 64)
	{ // Si la posy es mayor que el ancho, la direccion de Y sube
		// Si la posY es mayor que el ancho de la pantalla
		PosY = 0;
		PosX = 0;
		//m_score -= 1;
		//m_scoreString = to_string(m_score).c_str();
		//UpdateData(FALSE);
		MessageBeep(MB_OK);
		//PlaySound(TEXT("au.wav"), NULL, SND_FILENAME);
	}

	PosX += DirX;
	PosY = PosY + DirY;
}

void CBall::fn_collider(RECT rect,int barwith,int barwith2)
{
	if (PosY + m_BitBallHeight > rect.bottom - 50)
	{
		// Condiciones Mouse Middle
		if (PosX + m_BitBallHeight / 2 > barwith && PosX + m_BitBallHeight / 2 < barwith2) // m_BitBallHeight / 2 = 32
		{
			DirY = -5;
		}
	}
}