#ifndef RECTDRAWING_H
#define RECTDRAWING_H

#pragma once
#include "Drawing.h"
#include <vector>
class CRectDrawing :
	public CDrawing
{
public:
	CRectDrawing(int Thickness, COLORREF lineColor, COLORREF fillColor, CPoint startpt);
	~CRectDrawing();
	virtual void Draw(CDC& dc);
	void setEndpt(CPoint endpt);
	virtual int FindXYinLine(CPoint point);
private:
};

#endif