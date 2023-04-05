#include "Controller.h"


Controller::Controller() {
	m_table.SetSize(TABLE_SIZE_X, TABLE_SIZE_Y);
}

Controller::~Controller() {
}

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
