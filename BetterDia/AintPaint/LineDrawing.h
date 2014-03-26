#ifndef LINEDRAWING_H
#define LINEDRAWING_H
#pragma once
#include "Drawing.h"
#include <vector>

class CLineDrawing :
	public CDrawing
{
public:
	CLineDrawing(int Thickness, COLORREF lineColor, COLORREF fillColor, CPoint startpt);
	~CLineDrawing();
	virtual void Draw(CDC& dc);
	void setEndpt(CPoint endpt);
	virtual int FindXYinLine(CPoint point);
private:
};
#endif
