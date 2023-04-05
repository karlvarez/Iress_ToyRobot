#include "Global.h"
#include "Robot.h"

#include <iostream>

Robot::Robot() {
	/* Constructor */

	m_pos.x = POS_NOTSET;
	m_pos.y = POS_NOTSET;
	m_pos.face = FACE_NOTSET;
}

Robot::~Robot() {
	/* Destructor */

}

long Robot::GetX() {
	return m_pos.x;
}

long Robot::GetY() {
	return m_pos.y;
}

Face Robot::GetFace() {
	return m_pos.face;
}

void Robot::SetX(long x) {
	m_pos.x = x;
}
void Robot::SetY(long y) {
	m_pos.y = y;
}
void Robot::SetFace(Face face) {
	m_pos.face = face;
}

/*
* Parameters:
* x		: x position the robot is to be placed
* xmin	: the minimum x position that is allowed; e.g. based on the table size
* xmax	: the maximum x position that is allowed; e.g. based on the table size
* y		: y position the robot is to be placed
* ymin	: the minimum y position that is allowed; e.g. based on the table size
* ymax	: the maximum y position that is allowed; e.g. based on the table size
* face	: the face/direction the robot will be placed in
*
* Return value:
* true	: executing the place command on x, y will result in a valid position. ok to call Place().
* false	: executing the place command on x, y will result in an invalid position e.g. robot falls off the table or invalid direction. 
*/
bool Robot::TryPlace(long x, long xmin, long xmax, long y, long ymin, long ymax, Face face)
{
	bool bRet = isValidNewPos(x, xmin, xmax, y, ymin, ymax, face);
	return bRet;
}

/*
* Parameters:
* x		: x position the robot is to be placed
* y		: y position the robot is to be placed
* face	: the face/direction the robot will be placed in
*/
void Robot::Place(long x, long y, Face face)
{
	SetX(x);
	SetY(y);
	SetFace(face);
}

/*
* Parameters:
* xmin	: the minimum x position that is allowed; e.g. based on the table size
* xmax	: the maximum x position that is allowed; e.g. based on the table size
* ymin	: the minimum y position that is allowed; e.g. based on the table size
* ymax	: the maximum y position that is allowed; e.g. based on the table size
*
* Return value:
* true	: executing the move command will result in a valid position. ok to call Move().
* false	: executing the move command will result in an invalid position e.g. robot falls off the table.
*/
bool Robot::TryMove(long xmin, long xmax, long ymin, long ymax) {
	bool bRet = false;

	if (isValidPos()) {
		switch (m_pos.face) {
		case FACE_N:
			bRet = isValidNewPos(m_pos.x, xmin, xmax, m_pos.y + 1, ymin, ymax, m_pos.face);
			break;
		case FACE_S:
			bRet = isValidNewPos(m_pos.x, xmin, xmax, m_pos.y - 1, ymin, ymax, m_pos.face);
			break;

		case FACE_E:
			bRet = isValidNewPos(m_pos.x + 1, xmin, xmax, m_pos.y, ymin, ymax, m_pos.face);
			break;
		case FACE_W:
			bRet = isValidNewPos(m_pos.x - 1, xmin, xmax, m_pos.y, ymin, ymax, m_pos.face);
			break;

		default:
			break;
		}
	}

	return bRet;
}

/*
* Moves the robot 1 unit along the direction it is facing
*/
void Robot::Move() {
	switch (m_pos.face) {
	case FACE_N:
		SetY(m_pos.y + 1);
		break;
	case FACE_S:
		SetY(m_pos.y - 1);
		break;

	case FACE_E:
		SetX(m_pos.x + 1);
		break;
	case FACE_W:
		SetX(m_pos.x - 1);
		break;

	default:
		break;
	}
}

/*
* change the direction the robot is facing, 90 degrees to the Left or Counter-Clockwise, relative to where it is currently facing
* Return value:
* true	: command was executed successfully.
* false	: command failed. direction/face was not changed.
*/
bool Robot::Left() {
	bool bRet = false;

	if (isValidPos())
	{
		switch (m_pos.face) {
		case FACE_N:
			SetFace(FACE_W);
			break;
		case FACE_S:
			SetFace(FACE_E);
			break;

		case FACE_E:
			SetFace(FACE_N);
			break;
		case FACE_W:
			SetFace(FACE_S);
			break;

		default:
			break;
		}

		bRet = true;
	}

	return bRet;
}

/*
* change the direction the robot is facing, 90 degrees to the Right or Clockwise, relative to where it is currently facing
* Return value:
* true	: command was executed successfully.
* false	: command failed. direction/face was not changed.
*/
bool Robot::Right() {
	bool bRet = false;

	if (isValidPos()) {
		switch (m_pos.face) {
		case FACE_N:
			SetFace(FACE_E);
			break;
		case FACE_S:
			SetFace(FACE_W);
			break;

		case FACE_E:
			SetFace(FACE_S);
			break;
		case FACE_W:
			SetFace(FACE_N);
			break;

		default:
			break;
		}

		bRet = true;
	}

	return bRet;
}

/*
* display the current position of the robot and the direction that the robot is facing
*/ 
void Robot::Report() {
	/* TODO: remove calls to std output */

	if (!isValidPos())
	{
		std::cout << "Invalid position or face, issue a valid PLACE command first" << std::endl;
		return;
	}

	std::string sFace;
	std::string sReport;

	switch (m_pos.face) {
	case FACE_N:
		sFace = S_FACE_N;
		break;
	case FACE_S:
		sFace = S_FACE_S;
		break;

	case FACE_E:
		sFace = S_FACE_E;
		break;
	case FACE_W:
		sFace = S_FACE_W;
		break;

	default:
		break;
	}

	std::cout << "Output: " << m_pos.x << "," << m_pos.y << "," << sFace << std::endl;
}

/*
* Return value:
* true	: current x, y and face are valid. robot has previosly been placed successfully.
* false	: command failed. direction/face was not changed.
*/
bool Robot::isValidPos() {
	return (m_pos.x != POS_NOTSET) &&
		(m_pos.y != POS_NOTSET) &&
		(m_pos.face != FACE_NOTSET);
}

/*
* Utility function used by TryPlace() and TryMove(); moved shared logic here for maintainability
* Parameters:
* see TryPlace()
* Return value:
* true	: current x, y and face are valid. robot has previosly been placed successfully.
* false	: command failed. direction/face was not changed.
*/
bool Robot::isValidNewPos(long x, long xmin, long xmax, long y, long ymin, long ymax, Face face) {
	bool bRet = false;

	if (x >= xmin &&
		x <= xmax &&
		y >= ymin &&
		y <= ymax &&
		face != FACE_NOTSET) {
		bRet = true;
	}

	return bRet;
}
