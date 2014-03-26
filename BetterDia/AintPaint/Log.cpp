#include "stdafx.h"
#include "Log.h"


CLog::CLog()
{
}


CLog::~CLog()
{
	int iter;
	for (iter = 0; iter < vpDrawings.size(); iter++)
	{
		delete vpDrawings[iter];
	}
}


void CLog::Append(CDrawing * pDrawing)
{
	vpDrawings.push_back(pDrawing);
	
}


void CLog::DrawAll(CDC& dc)
{
	int iter;
	for (iter = 0; iter < (int)vpDrawings.size(); iter++)
	{
		vpDrawings[iter]->Draw(dc);
	}
}


CDrawing * CLog::FindXYinLine(CPoint point)
{
	int iter;
	// Start from the bottom of the log to maintain Z level
	for (iter = (int)vpDrawings.size() -1; iter >= 0 ; iter--)
	{
		// Found Drawing containing the clicked XY
		if (vpDrawings[iter]->FindXYinLine(point))
		{
			AfxMessageBox(_T("Found Object"));
			return vpDrawings[iter];
		}
	}
	return 0;
}

// Search vector of Drawings for Drawing with DrawingID and then move to end of vector
int CLog::BringtoFront(int DrawingID)
{
	int iter;
	// Start from the bottom of the log to maintain Z level
	for (iter = (int)vpDrawings.size() - 1; iter >= 0; iter--)
	{
		// Found Drawing containing the clicked XY
		if (vpDrawings[iter]->getID() == DrawingID)
		{
			vpDrawings.push_back(vpDrawings[iter]);
			vpDrawings.erase(vpDrawings.begin() + iter);
		}
	}
	return 0;
}


int CLog::SaveToFile(std::string FileName)
{
	std::ofstream myfile;
	myfile.open(FileName);

	int iter1, iter2;
	// Start from the top of the log and save to text file
	for (iter1 = 0; iter1 < (int)vpDrawings.size(); iter1++)
	{
		myfile << vpDrawings[iter1]->GetType() << " " << vpDrawings[iter1]->GetThickness() << " "
			<< std::hex << (int)vpDrawings[iter1]->GetLineColor() << " " << std::hex << (int)vpDrawings[iter1]->GetFillColor();

		for (iter2 = 0; iter2 < vpDrawings[iter1]->vXYpoints.size(); iter2++)
		{
			myfile << " " << std::dec << vpDrawings[iter1]->vXYpoints[iter2].x << " " << std::dec << vpDrawings[iter1]->vXYpoints[iter2].y;
		}
		myfile << std::endl;
	}

	myfile.close();
	return 0;
}


int CLog::Clear()
{
	vpDrawings.clear();
	return 0;
}
