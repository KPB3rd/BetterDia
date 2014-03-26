#pragma once
#include "Drawing.h"
class CClassBoxDrawing :
	public CDrawing
{
public:
	CClassBoxDrawing(CPoint UpperLeftCornerPt);
	virtual void Draw(CDC& dc);
	virtual int FindXYinLine(CPoint point);
	~CClassBoxDrawing();
private:
	CPoint startpt;
};

