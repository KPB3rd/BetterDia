#include "stdafx.h"
#include "SquareDrawing.h"


CSquareDrawing::CSquareDrawing(int Thickness, COLORREF lineColor, COLORREF fillColor, CPoint startpt)
{
	vXYpoints.push_back(startpt);
	SetType("Square");
	SetThickness(Thickness);
	SetLineColor(lineColor);
	SetFillColor(fillColor);
}


CSquareDrawing::~CSquareDrawing()
{
}

void CSquareDrawing::setEndpt(CPoint endpt)
{
	// If there's already an endpt, replace it
	if (vXYpoints.size() == 2)
	{
		vXYpoints.pop_back();
	}

	vXYpoints.push_back(endpt);
}

void CSquareDrawing::Draw(CDC& dc)
{
	// Outline
	CPen pen(PS_SOLID, GetThickness(), GetLineColor());
	dc.SelectObject(pen);
	// Fill
	CBrush fillBrush(GetFillColor());
	dc.SelectObject(fillBrush);

	int iter, sideLength = 0;
	for (iter = 0; iter < 1; iter++)
	{
		// Rectangle: StartingX, StartingY, EndingX, EndingY
		sideLength = abs(vXYpoints[iter].x - vXYpoints[iter + 1].x);
		CRect Rect(vXYpoints[iter].x, vXYpoints[iter].y, vXYpoints[iter].x + sideLength, vXYpoints[iter].y + sideLength);
		dc.Rectangle(Rect);
	}
}

int CSquareDrawing::FindXYinLine(CPoint point)
{
	int iter, threshold = 10;
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
		
	}
	return 0;
}