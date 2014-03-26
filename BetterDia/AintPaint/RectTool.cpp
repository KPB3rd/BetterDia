#include "stdafx.h"
#include "RectTool.h"


CRectTool::CRectTool()
{
}


CRectTool::~CRectTool()
{
}

void CRectTool::onMouseMove(CPoint point, CLog * pLog)
{
	if (downClickActive)
	{
		//AfxMessageBox(_T("MouseMove from LineTool"));
		endpt = point;
		// Create new Drawing
		if (firstMouseMove)
		{
			pLineDrawing = new CRectDrawing(GetThickness(), GetLineColor(), GetFillColor(), startpt);
			pLineDrawing->setEndpt(endpt);

			// Add drawing to Log
			pLog->Append(pLineDrawing);

			firstMouseMove = 0;
		}
		else // Modify existing Drawing
		{
			pLineDrawing->setEndpt(endpt);
		}
	}

}
void CRectTool::onDownClick(CPoint point, CLog * pLog)
{
	//AfxMessageBox(_T("DownClick from LineTool"));
	downClickActive = 1;
	firstMouseMove = 1;
	startpt = point;

}
void CRectTool::onUpClick(CPoint point, CLog * pLog)
{
	//AfxMessageBox(_T("UpClick from LineTool"));
	downClickActive = 0;
	firstMouseMove = 1;
	pLineDrawing = NULL;
	if (startpt == endpt)
	{
		delete pLineDrawing;
		pLineDrawing = NULL;
	}
}


int CRectTool::BringtoFront(CLog * pLog)
{
	return 0;
}

void CRectTool::onDoubleClick(CPoint point, CLog * pLog)
{
}


void CRectTool::EndDrawing()
{
}
