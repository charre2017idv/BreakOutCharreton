#pragma once
class CBar
{
public:
	CBar();
	~CBar();
public:
	void fn_movment(RECT rect, int x);
	void fn_paintBar(RECT rect, CDC* pDC);
public:
	int m_mousePosX;
	int m_xWidth1;
	int m_xWidth2;
	int m_leftSideBar;
	int m_rightSideBar;
	int m_bottomSideBar;
};

