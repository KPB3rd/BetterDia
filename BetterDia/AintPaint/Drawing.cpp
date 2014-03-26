#include "stdafx.h"
#include "Drawing.h"


CDrawing::CDrawing()
: thickness(0)
{
}


CDrawing::~CDrawing()
{
}


int CDrawing::getID()
{
	return ID;
}

int CDrawing::SetLineColor(COLORREF color)
{
	lineColor = color;
	return 0;
}

COLORREF CDrawing::GetLineColor()
{
	return lineColor;
}

int CDrawing::SetFillColor(COLORREF color)
{
	fillColor = color;
	return 0;
}

COLORREF CDrawing::GetFillColor()
{
	return fillColor;
}

int CDrawing::SetThickness(int Thickness)
{
	thickness = Thickness;
	return 0;
}

COLORREF CDrawing::GetThickness()
{
	return thickness;
}

void CDrawing::setEndpt(CPoint point)
{
}


std::string CDrawing::GetType()
{
	return DrawingType;
}


int CDrawing::SetType(std::string Type)
{
	DrawingType = Type;
	return 0;
}
