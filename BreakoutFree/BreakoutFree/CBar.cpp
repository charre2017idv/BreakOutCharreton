#include "stdafx.h"
#include "CBar.h"


CBar::CBar()
{
}


CBar::~CBar()
{
}

void CBar::fn_paintBar(RECT rect, CDC* pDC)
{
	pDC->Rectangle(m_xWidth1, rect.bottom - 20, m_xWidth2, rect.bottom - 50);
}


void CBar::fn_movment(RECT rect, int x)
{
	m_xWidth1 = x - 50;
	m_xWidth2 = x + 50;
	// Stop in left
	if (m_xWidth1 < rect.left)
	{
		m_xWidth1 = rect.left;
		m_xWidth2 = m_xWidth1 + 100;
	}
	// Stop in right
	else if (m_xWidth2 > rect.right)
	{
		m_xWidth2 = rect.right;
		m_xWidth1 = m_xWidth2 - 100;
	}
}