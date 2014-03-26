// Canvas.cpp : implementation file
//

#include "stdafx.h"
#include "AintPaint.h"
#include "Canvas.h"

// Canvas

IMPLEMENT_DYNAMIC(Canvas, CWnd)

Canvas::Canvas()
{
	WNDCLASS wndclass;
	const CString className = _T("DrawCanvasClass");
	if (!::GetClassInfo(AfxGetInstanceHandle(), className, &wndclass))
	{
		memset(&wndclass, 0, sizeof(wndclass));
		wndclass.style = CS_DBLCLKS;
		wndclass.lpfnWndProc = ::DefWindowProc;
		wndclass.hInstance = AfxGetInstanceHandle();
		wndclass.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		wndclass.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
		wndclass.lpszClassName = className;
		//TODO: check for errors
		AfxRegisterClass(&wndclass);
	}

	vtoolList.push_back(&LineTool);
	//vtoolList.push_back(&PolyLineTool);
	vtoolList.push_back(&SquareTool);
	vtoolList.push_back(&RectTool);
	vtoolList.push_back(&CursorTool);
}

Canvas::~Canvas()
{
	delete pLog;
}


BEGIN_MESSAGE_MAP(Canvas, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
//	ON_WM_MBUTTONDBLCLK()
ON_WM_LBUTTONDBLCLK()
ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// Canvas message handlers

void Canvas::OnPaint()
{
	// Draw Log
	CPaintDC dc(this);
	pLog->DrawAll(dc);
}


void Canvas::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (pcurrentTool != NULL)
	{
		pcurrentTool->onDownClick(point,pLog);
		Invalidate();
	}
}


void Canvas::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (pcurrentTool != NULL)
	{
		pcurrentTool->onUpClick(point,pLog);
		Invalidate();
	}
}

void Canvas::OnMouseMove(UINT nFlags, CPoint point)
{
	if (pcurrentTool != NULL && MK_LBUTTON == nFlags)
	{
		pcurrentTool->onMouseMove(point,pLog);
		Invalidate();
	}
}


int Canvas::SetTool(int newTool)
{
	pcurrentTool = vtoolList[newTool];
	pcurrentTool->EndDrawing();

	return 0;
}


int Canvas::BringtoFront()
{
	pcurrentTool->BringtoFront(pLog);
	Invalidate();
	return 0;
}

void Canvas::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	if (pcurrentTool != NULL)
	{
		pcurrentTool->onDoubleClick(point, pLog);
		Invalidate();
	}
}


void Canvas::SetLineColor(COLORREF color)
{
	if (pcurrentTool != NULL)
	{
		int iter;
		for (iter = 0; iter < (int)vtoolList.size(); iter++)
		{
			vtoolList[iter]->SetLineColor(color);
		}
	}
}

void Canvas::SetFillColor(COLORREF color)
{
	if (pcurrentTool != NULL)
	{
		int iter;
		for (iter = 0; iter < (int)vtoolList.size(); iter++)
		{
			vtoolList[iter]->SetFillColor(color);
		}
	}
}

void Canvas::SetThickness(int Thickness)
{
	if (pcurrentTool != NULL)
	{
		int iter;
		for (iter = 0; iter < (int)vtoolList.size(); iter++)
		{
			vtoolList[iter]->SetThickness(Thickness);
		}
	}
}

void Canvas::SaveAs()
{
	std::string fileName= "DrawingTxtFile.txt";
	pLog->SaveToFile(fileName);

	AfxMessageBox(_T("Drawing saved."));
}


void Canvas::Load()
{
	std::ifstream myfile("DrawingTxtFile.txt");
	std::string line;
	std::vector<std::string> tokens; // holds values read from line
	std::string buffer; // Have a buffer string
	CDrawing * pDrawing;
	std::string DrawingType;
	int LineThickness, iter;
	COLORREF LineColor;
	COLORREF FillColor;
	CPoint point;

	if (myfile.is_open())
	{
		// Empty the Existing Log
		pLog->Clear();

		// Gets line from saved file and splices values into vector
		while (getline(myfile, line))
		{
			// Insert the string into a stream
			std::stringstream ss(line); 

			// Read string stream into vector
			while (ss >> buffer)
			{
				tokens.push_back(buffer);
			}
			
			// Read Drawing Settings
			DrawingType = tokens[DRAWINGTYPE];
			LineThickness = atoi(tokens[LINETHICKNESS].c_str());

			std::istringstream buffer(tokens[LINECOLOR].c_str());
			buffer >> std::hex >> LineColor;

			buffer.clear();
			buffer.str(tokens[FILLCOLOR].c_str());
			buffer >> std::hex >> FillColor;

	
			buffer.clear();
			buffer.str(tokens[POINTX].c_str());
			buffer >> std::dec >> point.x;

			buffer.clear();
			buffer.str(tokens[POINTY].c_str());
			buffer >> std::dec >> point.y;

			if (DrawingType == "Line")
			{
				pDrawing = new CLineDrawing(LineThickness, LineColor, FillColor, point);
			}
			else if (DrawingType == "PolyLine")
			{
				pDrawing = new CPolyLineDrawing(LineThickness, LineColor, FillColor, point);
			}
			else if (DrawingType == "Square")
			{
				pDrawing = new CClassBoxDrawing(point);
			}
			else if (DrawingType == "Rectangle")
			{
				pDrawing = new CRectDrawing(LineThickness, LineColor, FillColor, point);
			}

			for (iter = NUM_TOKENS; iter < (int)(tokens.size() - 1); iter += 2)
			{
				// Read (X,Y) Point
				point.x = atol(tokens[iter].c_str());
				point.y = atol(tokens[iter + 1].c_str());

				pDrawing->setEndpt(point);
			}

			// Use tokens to create Drawing in Log
			pLog->Append(pDrawing);

			tokens.clear();
		}
		myfile.close();
	}
	else AfxMessageBox(_T("Unable to open file"));

	Invalidate();
	//AfxMessageBox(_T("Loaded"));
}


BOOL Canvas::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	//return false;
	return CWnd::OnEraseBkgnd(pDC);
}
