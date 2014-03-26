#include "Drawing.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#pragma once
class CLog
{
public:
	CLog();
	~CLog();
	void Append(CDrawing * pDrawing);
	void DrawAll(CDC& dc);
	CDrawing * FindXYinLine(CPoint point);
	int BringtoFront(int DrawingID);
	int SaveToFile(std::string FileName);
	int Clear();
private:
	std::vector<CDrawing *> vpDrawings;
};

