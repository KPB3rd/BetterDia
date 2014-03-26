#ifndef DRAWING_H
#define DRAWING_H
#pragma once
#include <string>
#include <vector>
class CDrawing
{
public:
	CDrawing();
	~CDrawing();
	virtual void Draw(CDC& dc) = 0;
	virtual int FindXYinLine(CPoint point) = 0;
	int getID();
	virtual int SetLineColor(COLORREF color);
	COLORREF GetLineColor();
	virtual int SetFillColor(COLORREF color);
	COLORREF GetFillColor();
	virtual int SetThickness(int Thickness);
	COLORREF GetThickness();
	std::string GetType();
	int SetType(std::string Type);
	virtual void setEndpt(CPoint point);
	std::vector<CPoint> vXYpoints;
private:
	int thickness;
	COLORREF fillColor;
	COLORREF lineColor;
	std::string DrawingType;
	int ID = rand() % 50000;
};
#endif
