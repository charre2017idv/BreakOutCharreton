
// BreakoutFreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BreakoutFree.h"
#include "BreakoutFreeDlg.h"
#include "afxdialogex.h"
#include <string>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBreakoutFreeDlg dialog



CBreakoutFreeDlg::CBreakoutFreeDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_BREAKOUTFREE_DIALOG, pParent)
	, Positionx(_T(""))
	, Positiony(_T(""))
	, m_levelName(_T(""))
	, m_loadLevelName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBreakoutFreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Gameplay, m_gameplay);
	DDX_Control(pDX, IDC_CREATE, m_gameEditor);
	DDX_Control(pDX, IDC_MAKEBRICK, m_makeBrick);
	DDX_Control(pDX, IDC_SUBMIT, m_submitBrick);
	DDX_Control(pDX, IDC_SAVELEVEL, m_saveLevel);
	DDX_Control(pDX, IDC_BACK, m_back);
	DDX_Text(pDX, IDC_positionX, Positionx);
	DDX_Text(pDX, IDC_positionY, Positiony);
	DDX_Control(pDX, IDC_NombreNivel, m_NameLevel);
	DDX_Text(pDX, IDC_NombreNivel, m_levelName);
	DDX_Text(pDX, IDC_EDIT2, m_loadLevelName);
}

BEGIN_MESSAGE_MAP(CBreakoutFreeDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PLAY, &CBreakoutFreeDlg::OnBnClickedPlay)
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_CREATE, &CBreakoutFreeDlg::OnBnClickedCreate)
	ON_BN_CLICKED(IDC_BACK, &CBreakoutFreeDlg::OnBnClickedBack)
	ON_BN_CLICKED(IDC_MAKEBRICK, &CBreakoutFreeDlg::OnBnClickedMakebrick)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_SAVELEVEL, &CBreakoutFreeDlg::OnBnClickedSavelevel)
	ON_BN_CLICKED(IDC_BUTTON6, &CBreakoutFreeDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_SUBMIT, &CBreakoutFreeDlg::OnBnClickedSubmit)
	ON_EN_CHANGE(IDC_NombreNivel, &CBreakoutFreeDlg::OnEnChangeNombrenivel)
END_MESSAGE_MAP()


// CBreakoutFreeDlg message handlers

BOOL CBreakoutFreeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_gameplay.GetClientRect(&Dimensions);
	Area = m_gameplay.GetDC();
	//Ball = new CBall(this->GetDC());
	Scene = new CScene();
	Ball = new CBall(Area);
	Bar = new CBar();
	Brick = new CBrick(Area);
	GameEditor = new CEditor();
	
	m_gameEditor.ShowWindow(SW_SHOW);
	m_makeBrick.ShowWindow(SW_HIDE);
	m_submitBrick.ShowWindow(SW_HIDE);
	m_saveLevel.ShowWindow(SW_HIDE);
	m_back.ShowWindow(SW_HIDE);
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBreakoutFreeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		m_gameplay.GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		
	}
		CDialog::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBreakoutFreeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBreakoutFreeDlg::fn_Scene()
{
	Scene->fn_frame(this->GetDC(), Dimensions);
}

void CBreakoutFreeDlg::fn_Ball(int x)
{
	Ball->fn_paintBall(this->GetDC());
	Ball->fn_movment(Dimensions, x);
	Ball->fn_collider(Dimensions,Bar->m_xWidth1,Bar->m_xWidth2);
	//Ball->fn_movment(Area);
}

void CBreakoutFreeDlg::fn_Bar(int x)
{
	Bar->fn_paintBar(Dimensions, this->GetDC());
	Bar->fn_movment(Dimensions, x);
}

void CBreakoutFreeDlg::fn_Brick(int i)
{
	Brick->fn_paintBrick(Area,Scene->BricksPositions[i]->m_PosX,Scene->BricksPositions[i]->m_PosY);
	Brick->fn_Collider(Ball->PosY, Ball->PosX,Ball->DirY,Ball->DirX,Ball->m_BitBallHeight, Scene->BricksPositions[i]->m_PosX, Scene->BricksPositions[i]->m_PosY, Scene->BricksPositions[i]->m_Resistance);
}

void CBreakoutFreeDlg::OnBnClickedPlay()
{

	SetTimer(1, 30, NULL);
	// TODO: Add your control notification handler code here
}

void CBreakoutFreeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent==2)
	{
		fn_Scene();
		for (int i = 0; i < GameEditor->Bricks.size(); i++)
		{
			Brick->fn_paintBrick(Area, GameEditor->Bricks[i]->m_PosX,GameEditor->Bricks[i]->m_PosY);
		}
		// Es posible que no funcione en el editor, por lo tanto puede que sea mejor eliminar los objetos en entra parte
		if (nIDEvent != 2)
		{
			delete(Scene);
			delete(Ball);
			delete(Bar);

		}
		Brick->fn_paintBrick(Area,m_mouseX,m_mouseY);
	}
	else
	{
		fn_Scene();
		fn_Ball(m_positionX);
		fn_Bar(m_positionX);
		for (int i = 0; i < Scene->BricksPositions.size() ; i++)
		{
			//if (Scene->BricksPositions[i]->m_exist)
			//{
			//}
			Scene->m_brickCounter = Scene->BricksPositions.size();
			if (Scene->BricksPositions[i]->m_exist)
			{
				Brick->fn_paintBrick(Area, Scene->BricksPositions[i]->m_PosX, Scene->BricksPositions[i]->m_PosY);
				Brick->fn_Collider(Ball->PosY, Ball->PosX, Ball->DirY, Ball->DirX, Ball->m_BitBallHeight,Scene->BricksPositions[i]->m_PosX,Scene->BricksPositions[i]->m_PosY, Scene->BricksPositions[i]->m_Resistance);
				//delete(Ball);
				//delete(Scene);
			}
			//fn_Brick(i);
			if (Scene->BricksPositions[i]->m_Resistance < 1)
			{
				Scene->BricksPositions[i]->m_exist = false;
				delete(Scene->BricksPositions[i]);
				Scene->BricksPositions.erase(Scene->BricksPositions.begin() + i);
				
			}
			
		}
		
	}
	//fn_Ball();
	//CDialog::OnTimer(nIDEvent);
}


void CBreakoutFreeDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	m_positionX = point.x;
	// TODO: Add your message handler code here and/or call default
	m_mouseX = point.x;
	m_mouseY = point.y;

	Brick->m_PosX = m_mouseX;
	Brick->m_PosY = m_mouseY;
	// Position on screen
	Positionx = to_string(point.x).c_str();
	Positiony = to_string(point.y).c_str();
	//UpdateData(TRUE);
	CDialog::OnMouseMove(nFlags, point);
}


void CBreakoutFreeDlg::OnBnClickedCreate()
{
	m_gameEditor.ShowWindow(SW_HIDE);
	m_makeBrick.ShowWindow(SW_SHOW);
	m_submitBrick.ShowWindow(SW_HIDE);
	m_saveLevel.ShowWindow(SW_SHOW);
	m_back.ShowWindow(SW_SHOW);
	m_NameLevel.ShowWindow(SW_SHOW);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CBreakoutFreeDlg::OnBnClickedBack()
{
	m_gameEditor.ShowWindow(SW_SHOW);
	m_makeBrick.ShowWindow(SW_HIDE);
	m_submitBrick.ShowWindow(SW_HIDE);
	m_saveLevel.ShowWindow(SW_HIDE);
	m_back.ShowWindow(SW_HIDE);
	m_NameLevel.ShowWindow(SW_HIDE);
	KillTimer(2);
	// TODO: Add your control notification handler code here
}


void CBreakoutFreeDlg::OnBnClickedMakebrick()
{
	//Brick = new CBrick(Area);
	SetTimer(2,30,NULL);
	// TODO: Add your control notification handler code here
}


void CBreakoutFreeDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CBrick *NEWBRICK = new CBrick(Area);
	NEWBRICK->m_PosX = Brick->m_PosX;
	NEWBRICK->m_PosY = Brick->m_PosY;
	GameEditor->Bricks.push_back(NEWBRICK);

	CDialog::OnLButtonDown(nFlags, point);
}


void CBreakoutFreeDlg::OnBnClickedSavelevel()
{
	// Pass CString to string value
	UpdateData(TRUE);
	CT2CA CstringtoString(m_levelName);
	UpdateData(FALSE);
	string level;
	level = CstringtoString;
	// Save the level
	GameEditor->fn_saveLevel(level);
	// TODO: Add your control notification handler code here
}


void CBreakoutFreeDlg::OnBnClickedButton6()
{
	// Pass CString to string value
	UpdateData(TRUE);
	CT2CA CstringtoStringLoad(m_loadLevelName);
	UpdateData(FALSE);
	string levelLoad;
	levelLoad = CstringtoStringLoad;
	// Load the level
	if (levelLoad != " ")
		Scene->fn_loadLevel(levelLoad);
	else
		Scene->fn_loadLevel("Level.txt");
	// TODO: Add your control notification handler code here
}


void CBreakoutFreeDlg::OnBnClickedSubmit()
{
	// TODO: Add your control notification handler code here
}


void CBreakoutFreeDlg::OnEnChangeNombrenivel()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO:  Add your control notification handler code here
}
