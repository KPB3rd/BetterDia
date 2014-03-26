#ifndef SQUARETOOL_H
#define SQUARETOOL_H

#pragma once
#include "Tool.h"
#include "ClassBoxDrawing.h"

class CSquareTool :
	public CTool
{
public:
	CSquareTool();
	~CSquareTool();
	virtual void onMouseMove(CPoint point, CLog * pLog);
	virtual void onDownClick(CPoint point, CLog * pLog);
	virtual void onUpClick(CPoint point, CLog * pLog);
	virtual int BringtoFront(CLog * pLog);
	virtual void onDoubleClick(CPoint point, CLog * pLog);
	virtual void EndDrawing();

private:
	CPoint startpt;
	CPoint endpt;
	CClassBoxDrawing * pLineDrawing = NULL;
};
#endif
