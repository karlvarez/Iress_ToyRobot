#include "Global.h"
#include "Robot.h"
#pragma once

#define SIZE_NOTSET -1

class Table
{
private:
	long m_xsize = SIZE_NOTSET;
	long m_ysize = SIZE_NOTSET;
	Robot m_Robot1;

public:
	Table(long, long);
	~Table();

	bool PlaceRobot(long, long, Face);
	bool MoveRobot();
	bool LeftRobot();
	bool RightRobot();
	void ReportRobot();

	long GetXSize();
	long GetYSize();
};

