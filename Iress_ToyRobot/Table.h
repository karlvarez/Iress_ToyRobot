#pragma once

#include "Global.h"
#include "Robot.h"

#define SIZE_NOTSET -1

class Table
{
private:
	long m_xsize = SIZE_NOTSET;
	long m_ysize = SIZE_NOTSET;

	// Table class has 1 instance of Robot
	// consider changing to a vector or other data structure in case additional robots will be supported, consider having an ID for each robot
	Robot m_Robot1;

public:
	Table();
	~Table();

	// set the size of the table (in units)
	// take note that the coordinate system of the Table is zero-based while size here is number of units
	void SetSize(long, long);

	// functions corresponding to all commands that the robot supports
	// the only reason a Table class is created is for future support for scenarios like: additional robots, additional rules regarding the table e.g. obstacles
	bool PlaceRobot(long, long, Face);
	bool MoveRobot();
	bool LeftRobot();
	bool RightRobot();
	void ReportRobot();

};

