
// AintPaintDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AintPaint.h"
#include "AintPaintDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
	
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAintPaintDlg dialog



CAintPaintDlg::CAintPaintDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAintPaintDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAintPaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CANVAS, m_canvas);
}

BEGIN_MESSAGE_MAP(CAintPaintDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAintPaintDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CANVAS, &CAintPaintDlg::OnBnClickedCanvasgroup)
	ON_BN_CLICKED(IDOK, &CAintPaintDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &CAintPaintDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &CAintPaintDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CAintPaintDlg::OnBnClickedButton8)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR2, &CAintPaintDlg::OnNMThemeChangedScrollbar2)
END_MESSAGE_MAP()


// CAintPaintDlg message handlers

BOOL CAintPaintDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAintPaintDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

void CAintPaintDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAintPaintDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// Line Button
void CAintPaintDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	m_canvas.SetTool(ToolButtonID(LINE));
}


void CAintPaintDlg::OnBnClickedCanvasgroup()
{
	// TODO: Add your control notification handler code here

}

void CAintPaintDlg::OnBnClickedOk()
{
	CDialogEx::OnOK();
}


// Square Button
void CAintPaintDlg::OnBnClickedButton3()
{
	m_canvas.SetTool(ToolButtonID(SQUARE));
}



// Save As... Button
void CAintPaintDlg::OnBnClickedButton7()
{
	m_canvas.SaveAs();
}


void CAintPaintDlg::OnBnClickedButton8()
{
	m_canvas.Load();
}


void CAintPaintDlg::OnNMThemeChangedScrollbar2(NMHDR *pNMHDR, LRESULT *pResult)
{
	// This feature requires Windows XP or greater.
	// The symbol _WIN32_WINNT must be >= 0x0501.
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
