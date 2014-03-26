#include "stdafx.h"
#include "ClassBoxDrawing.h"


CClassBoxDrawing::CClassBoxDrawing(CPoint UpperLeftCornerPt)
{
	startpt = UpperLeftCornerPt;
}


CClassBoxDrawing::~CClassBoxDrawing()
{
}

void CClassBoxDrawing::Draw(CDC& dc)
{
	// Outline
	CPen pen(PS_SOLID, 3, RGB(0,0,0));
	dc.SelectObject(pen);
	// Fill
	CBrush fillBrush(RGB(255, 255, 255));
	dc.SelectObject(fillBrush);

	// Rectangle: StartingX, StartingY, EndingX, EndingY
	// Draws a square 50x50 pixels
	CRect Rect(startpt.x, startpt.y, startpt.x + 50, startpt.y + 50);
	dc.Rectangle(Rect);
	
}

int CClassBoxDrawing::FindXYinLine(CPoint point)
{
/*	int iter, threshold = 10;
	float lineSlope = 0;
	float yintersect = 0;
	CPoint point1, point2;

	for (iter = 0; iter < (int)vXYpoints.size() - 1; iter++)
	{
		point1 = vXYpoints[iter];
		point2 = vXYpoints[iter + 1];


		// Check if point is inside the square
		int minX, maxX, minY, maxY;
		minX = min(point1.x, point2.x);
		maxX = max(point1.x, point2.x);
		minY = min(point1.y, point2.y);
		maxY = max(point1.y, point2.y);
		if ((minX <= point.x && point.x <= maxX) && (minY <= point.y && point.y <= maxY))
		{
			return 1;
		}

	}*/
	return 0;
}