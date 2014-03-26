#pragma once
#include "Tool.h"
class CCursorTool :
	public CTool
{
public:
	CCursorTool();
	~CCursorTool();
	virtual void onMouseMove(CPoint point, CLog * pLog);
	virtual void onDownClick(CPoint point, CLog * pLog);
	virtual void onUpClick(CPoint point, CLog * pLog);
	void FindXYinLine(CPoint point, CLog * pLog);
	virtual int BringtoFront(CLog * pLog);	
	virtual void onDoubleClick(CPoint point, CLog * pLog);
	virtual int SetThickness(int Thickness);
	virtual int SetLineColor(COLORREF LineColor);
	virtual int SetFillColor(COLORREF FillColor);

private:
	int downClickActive = 0;
	int firstMouseMove = 0;
	CPoint startpt;
	CPoint endpt;
	CDrawing * pLineDrawing = NULL;
	
public:
	virtual void EndDrawing();
};

