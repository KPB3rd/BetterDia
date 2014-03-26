
// AintPaintDlg.h : header file
//
#include "Canvas.h"

#pragma once


// CAintPaintDlg dialog
class CAintPaintDlg : public CDialogEx
{
// Construction
public:
	CAintPaintDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_AINTPAINT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private: 
	Canvas m_canvas;
	enum ToolButtonID { LINE, SQUARE, NUM_TOOLS };
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCanvasgroup();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnNMThemeChangedScrollbar2(NMHDR *pNMHDR, LRESULT *pResult);
};
