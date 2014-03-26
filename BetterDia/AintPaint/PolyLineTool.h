#ifndef POLYLINETOOL_H
#define POLYLINETOOL_H
#pragma once
#include "Tool.h"
#include "PolyLineDrawing.h"

class CPolyLineTool :
	public CTool
{
public:
	CPolyLineTool();
	~CPolyLineTool();
	virtual void onMouseMove(CPoint point, CLog * pLog);
	virtual void onDownClick(CPoint point, CLog * pLog);
	virtual void onUpClick(CPoint point, CLog * pLog);
	virtual int BringtoFront(CLog * pLog);
	virtual void onDoubleClick(CPoint point, CLog * pLog);
	virtual void EndDrawing();
private:
	int downClickActive = 0;
	int firstMouseMove = 0;
	int firstLineDone = 0;
	CPoint startpt;
	CPoint endpt;
	CPolyLineDrawing * pLineDrawing = NULL;
};
#endif
