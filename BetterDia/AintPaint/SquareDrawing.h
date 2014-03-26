#ifndef SQUAREDRAWING_H
#define SQUAREDRAWING_H
#pragma once
#include "Drawing.h"
#include <vector>

class CSquareDrawing :
	public CDrawing
{
public:
	CSquareDrawing(int Thickness, COLORREF lineColor, COLORREF fillColor, CPoint startpt);
	~CSquareDrawing();
	virtual void Draw(CDC& dc);
	void setEndpt(CPoint endpt);
	virtual int FindXYinLine(CPoint point);
private:
	
};

#endif
