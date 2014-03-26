#ifndef LINETOOL_H
#define LINETOOL_H
#pragma once
#include "Tool.h"
#include "Drawing.h"
#include "LineDrawing.h"

class CLineTool :
	public CTool
{
public:
	CLineTool();
	~CLineTool();
	virtual void onMouseMove(CPoint point, CLog * pLog);
	virtual void onDownClick(CPoint point, CLog * pLog);
	virtual void onUpClick(CPoint point, CLog * pLog);
	virtual int BringtoFront(CLog * pLog);
	virtual void onDoubleClick(CPoint point, CLog * pLog);

private:
	int downClickActive = 0;
	int firstMouseMove = 0;
	CPoint startpt;
	CPoint endpt;
	CLineDrawing * pLineDrawing = NULL;
public:
	virtual void EndDrawing();
};
#endif

