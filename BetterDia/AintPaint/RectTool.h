#ifndef RECTTOOL_H
#define RECTTOOL_H
#pragma once
#include "Tool.h"
#include "RectDrawing.h"
class CRectTool :
	public CTool
{
public:
	CRectTool();
	~CRectTool();
	virtual void onMouseMove(CPoint point, CLog * pLog);
	virtual void onDownClick(CPoint point, CLog * pLog);
	virtual void onUpClick(CPoint point, CLog * pLog);
	virtual int BringtoFront(CLog * pLog);
	virtual void onDoubleClick(CPoint point, CLog * pLog);
	virtual void EndDrawing();

private:
	int downClickActive = 0;
	int firstMouseMove = 0;
	CPoint startpt;
	CPoint endpt;
	CRectDrawing * pLineDrawing = NULL;
};

#endif