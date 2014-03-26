#include "stdafx.h"
#include "PolyLineTool.h"


CPolyLineTool::CPolyLineTool()
{
}


CPolyLineTool::~CPolyLineTool()
{
}

void CPolyLineTool::onMouseMove(CPoint point, CLog * pLog)
{
	if (downClickActive)
	{
		//AfxMessageBox(_T("MouseMove from LineTool"));
		endpt = point;
		pLineDrawing->setEndpt(endpt,1);
	}

}
void CPolyLineTool::onDownClick(CPoint point, CLog * pLog)
{
	//AfxMessageBox(_T("DownClick from LineTool"));
	downClickActive = 1;
	firstMouseMove = 1;
	if (firstLineDone)
	{
		endpt = point;
		pLineDrawing->setEndpt(endpt,0);
	}
	else // First Line Segment of PolyLine
	{
		startpt = point;
		endpt = point;
		pLineDrawing = new CPolyLineDrawing(GetThickness(), GetLineColor(), GetFillColor(), startpt);
		pLineDrawing->setEndpt(endpt,0);

		// Add drawing to Log
		pLog->Append(pLineDrawing);
	}
	

}
void CPolyLineTool::onUpClick(CPoint point, CLog * pLog)
{
	//AfxMessageBox(_T("UpClick from LineTool"));
	downClickActive = 0;
	if (startpt == endpt)
	{
		delete pLineDrawing;
		pLineDrawing = NULL;
	}
	else
	{
		firstLineDone = 1;
		startpt = point;
	}
}

int CPolyLineTool::BringtoFront(CLog * pLog)
{
	return 0;
}

void CPolyLineTool::onDoubleClick(CPoint point, CLog * pLog)
{
	pLineDrawing = NULL;
	firstLineDone = 0;
}

void CPolyLineTool::EndDrawing()
{
	pLineDrawing = NULL;
	firstLineDone = 0;
}