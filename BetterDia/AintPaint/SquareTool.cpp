#include "stdafx.h"
#include "SquareTool.h"


CSquareTool::CSquareTool()
{

}


CSquareTool::~CSquareTool()
{
}

void CSquareTool::onMouseMove(CPoint point, CLog * pLog)
{
	

}
void CSquareTool::onDownClick(CPoint point, CLog * pLog)
{
	//AfxMessageBox(_T("DownClick from LineTool"));
	pLineDrawing = NULL;
	pLineDrawing = new CClassBoxDrawing(point);

	// Add drawing to Log
	pLog->Append(pLineDrawing);
	pLineDrawing = NULL;
}

void CSquareTool::onUpClick(CPoint point, CLog * pLog)
{
	//AfxMessageBox(_T("UpClick from LineTool"));
	
}


int CSquareTool::BringtoFront(CLog * pLog)
{
	return 0;
}

void CSquareTool::onDoubleClick(CPoint point, CLog * pLog)
{
}


void CSquareTool::EndDrawing()
{
}
