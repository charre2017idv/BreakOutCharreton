
// BreakoutFreeDlg.h : header file
//

#pragma once
#include "CScene.h"
#include "CBall.h"
#include "CBar.h"
#include "CBrick.h"
#include "CEditor.h"
// CBreakoutFreeDlg dialog
class CBreakoutFreeDlg : public CDialog
{
// Construction
public:
	CBreakoutFreeDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BREAKOUTFREE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void fn_Ball(int x);
	void fn_Scene();
	void fn_Bar(int x);
	void fn_Brick(int i);
public:
	CDC *Area;
	RECT Dimensions;
	CScene *Scene;
	CBall *Ball;
	CBar *Bar;
	CBrick *Brick;
	CEditor *GameEditor;
public:
	int m_positionX;
	// Mouse Coordinates
	int m_mouseX = 0;
	int m_mouseY = 0;
	int m_resistance;

public:
	CStatic m_gameplay;
	afx_msg void OnBnClickedPlay();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CButton m_gameEditor;
	CButton m_makeBrick;
	CButton m_submitBrick;
	CButton m_saveLevel;
	afx_msg void OnBnClickedCreate();
	CButton m_back;
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedMakebrick();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedSavelevel();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedSubmit();
	CString Positionx;
	CString Positiony;
	afx_msg void OnEnChangeNombrenivel();
	CEdit m_NameLevel;
	CString m_levelName;
	CString m_loadLevelName;
};
