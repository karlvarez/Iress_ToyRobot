#pragma once

#include "Global.h"
#include "Table.h"

class Controller
{
private:
	Table m_table;

public:
	Controller();
	~Controller();
	bool Place(long, long, Face);
	bool Move();
	bool Left();
	bool Right();
	void Report();

};

