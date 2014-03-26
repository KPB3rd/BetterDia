#ifndef TOOL_H
#define TOOL_H

#include "afxwin.h"
#include "Log.h"

class CTool :
	public CButton
{
public:
	CTool();
	~CTool();
	virtual void onDownClick(CPoint point, CLog * pLog) = 0;
	virtual void onUpClick(CPoint point, CLog * pLog) = 0;
	virtual void onMouseMove(CPoint point, CLog * pLog) = 0;
	virtual int BringtoFront(CLog * pLog) = 0;
	virtual void onDoubleClick(CPoint point, CLog * pLog) = 0;
	virtual void EndDrawing() = 0;
	virtual int SetLineColor(COLORREF color);
	COLORREF GetLineColor();
	virtual int SetFillColor(COLORREF color);
	COLORREF GetFillColor();
	virtual int SetThickness(int Thickness);
	COLORREF GetThickness();
	DECLARE_MESSAGE_MAP()
private:
	// Default Settings
	COLORREF lineColor = 0;
	COLORREF fillColor = 0;
	int thickness = 3;
};
#endif