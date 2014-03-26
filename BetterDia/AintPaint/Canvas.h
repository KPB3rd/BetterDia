#ifndef CANVAS_H
#define CANVAS_H
#pragma once
#include "Tool.h"
#include "LineTool.h"
#include "PolyLineTool.h"
#include "SquareTool.h"
#include "CursorTool.h"
#include "RectTool.h"
#include "Log.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <vector>

// Canvas

class Canvas : public CWnd
{
	DECLARE_DYNAMIC(Canvas)

public:
	Canvas();
	virtual ~Canvas();
	CPoint startpt, endpt;
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int SetTool(int newTool);
	int BringtoFront();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	void SetLineColor(COLORREF color);
	void SetFillColor(COLORREF color);
	void SetThickness(int Thickness);
	void SaveAs();
	void Load();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
protected:
	DECLARE_MESSAGE_MAP()
private:
	CTool * pcurrentTool = NULL;
	CLineTool LineTool;
	CPolyLineTool PolyLineTool;
	CSquareTool SquareTool;
	CCursorTool CursorTool;
	CRectTool RectTool;
	CLog * pLog = new CLog;
	FILE * DrawingTxtFile;
	std::vector<CTool*> vtoolList;
	enum TOKENS { DRAWINGTYPE, LINETHICKNESS, LINECOLOR, FILLCOLOR, POINTX, POINTY, NUM_TOKENS };
};
#endif

