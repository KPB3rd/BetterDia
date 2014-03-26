#include "stdafx.h"
#include "CursorTool.h"
#include "Log.h"

CCursorTool::CCursorTool()
{

}


CCursorTool::~CCursorTool()
{

}

void CCursorTool::onMouseMove(CPoint point, CLog * pLog)
{
	firstMouseMove = 1;
}

void CCursorTool::onDownClick(CPoint point, CLog * pLog)
{
	downClickActive = 1;
}


void CCursorTool::onUpClick(CPoint point, CLog * pLog)
{
	// Click without movement
	if (!firstMouseMove && downClickActive) 
	{
		FindXYinLine(point, pLog);
	}
	downClickActive = 0;
	firstMouseMove = 0;
}

void CCursorTool::FindXYinLine(CPoint point, CLog * pLog)
{
	pLineDrawing = pLog->FindXYinLine(point);
}


int CCursorTool::BringtoFront(CLog * pLog)
{
	pLog->BringtoFront(pLineDrawing->getID());
	return 0;
}

void CCursorTool::onDoubleClick(CPoint point, CLog * pLog)
{
}


void CCursorTool::EndDrawing()
{
}

int CCursorTool::SetThickness(int Thickness)
{
	if (pLineDrawing != NULL)
	{
		pLineDrawing->SetThickness(Thickness);
	}
	return 0;
}

int CCursorTool::SetLineColor(COLORREF LineColor)
{
	if (pLineDrawing != NULL)
	{
		pLineDrawing->SetLineColor(LineColor);
	}
	return 0;
}

int CCursorTool::SetFillColor(COLORREF FillColor)
{
	if (pLineDrawing != NULL)
	{
		pLineDrawing->SetFillColor(FillColor);
	}
	return 0;
}