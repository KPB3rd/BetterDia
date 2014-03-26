#include "stdafx.h"
#include "Tool.h"
#include "AintPaint.h"

CTool::CTool()
{
}


CTool::~CTool()
{
}

BEGIN_MESSAGE_MAP(CTool, CButton)
END_MESSAGE_MAP()

int CTool::SetLineColor(COLORREF color)
{
	lineColor = color;
	return 0;
}

COLORREF CTool::GetLineColor()
{
	return lineColor;
}

int CTool::SetFillColor(COLORREF color)
{
	fillColor = color;
	return 0;
}

COLORREF CTool::GetFillColor()
{
	return fillColor;
}

int CTool::SetThickness(int Thickness)
{
	thickness = Thickness;
	return 0;
}

COLORREF CTool::GetThickness()
{
	return thickness;
}