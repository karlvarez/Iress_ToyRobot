#include "Controller.h"


Controller::Controller() {
	// since the current requirements is a fixed-size table, ok to set it here using the Globally defined table size
	// change this in case the table size is variable
	m_table.SetSize(TABLE_SIZE_X, TABLE_SIZE_Y);
}

Controller::~Controller() {
}


/*
* see header
*/
bool Controller::Place(long x, long y, Face face) {
	bool bRet = false;

	if (m_table.PlaceRobot(x, y, face)) {
		bRet = true;
	}

	return bRet;
}

bool Controller::Move() {
	bool bRet = false;

	if (m_table.MoveRobot()) {
		bRet = true;
	}

	return bRet;
}

bool Controller::Left() {
	bool bRet = false;

	if (m_table.LeftRobot()) {
		bRet = true;
	}

	return bRet;
}

bool Controller::Right() {
	bool bRet = false;

	if (m_table.RightRobot()) {
		bRet = true;
	}

	return bRet;
}

void Controller::Report() {
	m_table.ReportRobot();
}
