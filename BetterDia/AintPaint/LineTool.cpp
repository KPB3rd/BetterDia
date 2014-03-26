#include "stdafx.h"
#include "LineTool.h"
#include "Log.h"


CLineTool::CLineTool()
{

}


CLineTool::~CLineTool()
{
}

void CLineTool::onMouseMove(CPoint point, CLog * pLog)
{
	if (downClickActive)
	{
		//AfxMessageBox(_T("MouseMove from LineTool"));
		endpt = point;
		// Create new Drawing
		if (firstMouseMove)
		{
			pLineDrawing = new CLineDrawing(GetThickness(), GetLineColor(), GetFillColor(), startpt);
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
void CLineTool::onDownClick(CPoint point, CLog * pLog)
{
	//AfxMessageBox(_T("DownClick from LineTool"));
	downClickActive = 1;
	firstMouseMove = 1;
	startpt = point;

}
void CLineTool::onUpClick(CPoint point, CLog * pLog)
{
	//AfxMessageBox(_T("UpClick from LineTool"));
	downClickActive = 0;
	pLineDrawing = NULL;
	if (startpt == endpt)
	{
		delete pLineDrawing;
		pLineDrawing = NULL;
	}
}


int CLineTool::BringtoFront(CLog * pLog)
{
	return 0;
}

void CLineTool::onDoubleClick(CPoint point, CLog * pLog)
{
}


void CLineTool::EndDrawing()
{
}
