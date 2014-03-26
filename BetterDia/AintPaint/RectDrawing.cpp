#include "stdafx.h"
#include "RectDrawing.h"


CRectDrawing::CRectDrawing(int Thickness, COLORREF lineColor, COLORREF fillColor, CPoint startpt)
{
	vXYpoints.push_back(startpt);
	SetType("Rectangle");
	SetThickness(Thickness);
	SetLineColor(lineColor);
	SetFillColor(fillColor);
}


CRectDrawing::~CRectDrawing()
{
}

void CRectDrawing::setEndpt(CPoint endpt)
{
	// If there's already an endpt, replace it
	if (vXYpoints.size() == 2)
	{
		vXYpoints.pop_back();
	}

	vXYpoints.push_back(endpt);
}

void CRectDrawing::Draw(CDC& dc)
{
	// Outline
	CPen pen(PS_SOLID, GetThickness(), GetLineColor());
	dc.SelectObject(pen);
	// Fill
	CBrush fillBrush(GetFillColor());
	dc.SelectObject(fillBrush);

	int iter;
	for (iter = 0; iter < 1; iter++)
	{
		// Rectangle: StartingX, StartingY, EndingX, EndingY
		CRect Rect(vXYpoints[iter].x, vXYpoints[iter].y, vXYpoints[iter+1].x, vXYpoints[iter+1].y);
		dc.Rectangle(Rect);
	}
}

int CRectDrawing::FindXYinLine(CPoint point)
{
	int iter, threshold = 10;
	float lineSlope = 0;
	float yintersect = 0;
	CPoint point1, point2;

	for (iter = 0; iter < (int)vXYpoints.size() - 1; iter++)
	{
		point1 = vXYpoints[iter];
		point2 = vXYpoints[iter + 1];


		// Check if point is inside the rect
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