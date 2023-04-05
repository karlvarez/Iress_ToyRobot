#include "InputParser_Controller.h"


InputParser_Controller::InputParser_Controller() {
	m_table.SetSize(TABLE_SIZE_X, TABLE_SIZE_Y);
}

InputParser_Controller::~InputParser_Controller() {
}

bool InputParser_Controller::Place(long x, long y, Face face) {
	bool bRet = false;

	if (m_table.PlaceRobot(x, y, face)) {
		bRet = true;
	}

	return bRet;
}

bool InputParser_Controller::Move() {
	bool bRet = false;

	if (m_table.MoveRobot()) {
		bRet = true;
	}

	return bRet;
}

bool InputParser_Controller::Left() {
	bool bRet = false;

	if (m_table.LeftRobot()) {
		bRet = true;
	}

	return bRet;
}

bool InputParser_Controller::Right() {
	bool bRet = false;

	if (m_table.RightRobot()) {
		bRet = true;
	}

	return bRet;
}

void InputParser_Controller::Report() {
	m_table.ReportRobot();
}
