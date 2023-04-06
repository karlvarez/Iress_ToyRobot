#pragma once

#include "Global.h"
#include "Table.h"

/* constants */
// current requirements: 5x5 Table, change these to resize the table in the future
#define TABLE_SIZE_X 5
#define TABLE_SIZE_Y 5

class Controller
{
	// Controller class is only created as abstraction between the possible commands from the raw input and the Table and Robot classes
	// Controller class will also be used for any future enhancements that needs other elements e.g. graphical display

private:
	// Controller class has 1 instance of Table
	Table m_table;

public:
	Controller();
	~Controller();

	// functions corresponding to all commands that the robot supports
	// add more in case there are more commands to be supported and/or there are more high-level functionalities to be supported e.g. graphical display
	bool Place(long, long, Face);
	bool Move();
	bool Left();
	bool Right();
	void Report();

};

