#pragma once

#include "Global.h"
#include "Table.h"

class InputParser_Controller
{
private:
	Table m_table;

public:
	InputParser_Controller();
	~InputParser_Controller();
	bool Place(long, long, Face);
	bool Move();
	bool Left();
	bool Right();
	void Report();

};

