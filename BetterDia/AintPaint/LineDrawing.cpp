#include "stdafx.h"
#include "LineDrawing.h"


CLineDrawing::CLineDrawing(int Thickness, COLORREF lineColor, COLORREF fillColor, CPoint startpt)
{
	vXYpoints.push_back(startpt);
	SetType("Line");
	SetThickness(Thickness);
	SetLineColor(lineColor);
	SetFillColor(fillColor);
}


CLineDrawing::~CLineDrawing()
{
}


void CLineDrawing::setEndpt(CPoint endpt)
{
	// If there's already an endpt, replace it
	if (vXYpoints.size() == 2)
	{
		vXYpoints.pop_back();
	} 

	vXYpoints.push_back(endpt);
}

void CLineDrawing::Draw(CDC& dc)
{
	CPen pen(PS_SOLID, GetThickness(), GetLineColor());
	dc.SelectObject(pen);
	int iter;
	for (iter = 0; iter < 1; iter++)
	{
		// Starting pt, first xy value in the vector
		dc.MoveTo(vXYpoints[iter].x, vXYpoints[iter].y);
		// Ending pt, second xy value in the vector
		dc.LineTo(vXYpoints[iter + 1].x, vXYpoints[iter + 1].y);
	}
}

int CLineDrawing::FindXYinLine(CPoint point)
{
	int iter, threshold = 10;
	float lineSlope = 0;
	float yintersect = 0;
	CPoint point1, point2;

	for (iter = 0; iter < (int)vXYpoints.size() - 1; iter++)
	{
		point1 = vXYpoints[iter];
		point2 = vXYpoints[iter + 1];


		// Check if point is inside the straight vertical line segment
		if ((point1.x + point2.x - threshold < 2 * point.x) && (point1.x + point2.x + threshold > 2 * point.x) && // Same X axis
			((point.y > point1.y && point.y < point2.y) || ((point.y < point1.y && point.y > point2.y))))         // Inside segment
		{
			return 1;
		}
		// Check if point is inside the straight horizontal line segment
		else if ((point1.y + point2.y - threshold < 2 * point.y) && (point1.y + point2.y + threshold > 2 * point.y) && // Same Y axis
			((point.x > point1.x && point.x < point2.x) || ((point.x < point1.x && point.x > point2.x))))         // Inside segment
		{
			return 1;
		}
		// Check if point is inside the angled line segment
		else if (abs((point1.y - point.y)*(point1.x - point.x)) < abs((point1.y - point2.y)*(point1.x - point2.x)))
		{
			// Line slope
			lineSlope = ((float)point1.y - (float)point2.y) / ((float)point1.x - (float)point2.x);

			// Y intersect
			yintersect = point1.y - lineSlope * point1.x;

			// Point is in line or within threshold
			if ((point.y >= -threshold - GetThickness() + lineSlope * point.x + yintersect) && 
				(point.y <=  threshold + GetThickness() + lineSlope * point.x + yintersect))
			{
				return 1;
			}
		}
	}
	return 0;
}