#pragma once
#include "Drawing.h"
#include <vector>

class CPolyLineDrawing :
	public CDrawing
{
public:
	CPolyLineDrawing(int Thickness, COLORREF lineColor, COLORREF fillColor, CPoint startpt);
	~CPolyLineDrawing();
	virtual void Draw(CDC& dc);
	void setEndpt(CPoint endpt);
	void setEndpt(CPoint endpt, int isTemporaryEndpt);
	virtual int FindXYinLine(CPoint point);
private:
};

