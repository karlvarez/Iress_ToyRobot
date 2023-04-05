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

bool Robot::TryPlace(long x, long xmin, long xmax, long y, long ymin, long ymax, Face face)
{
	bool bRet = isValidNewPos(x, xmin, xmax, y, ymin, ymax, face);
	return bRet;
}

void Robot::Place(long x, long y, Face face)
{
	SetX(x);
	SetY(y);
	SetFace(face);
}

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

void Robot::Report() {
	/* TODO: remove calls to std output */

	if (!isValidPos())
	{
		std::cout << "Invalid position or face, issue a valid PLACE command first";
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

	sReport = "" + m_pos.x;
	sReport += ", " + m_pos.y;
	sReport += ", " + sFace;

	std::cout << sReport;
}

bool Robot::isValidPos() {
	return (m_pos.x != POS_NOTSET) &&
		(m_pos.y != POS_NOTSET) &&
		(m_pos.face != FACE_NOTSET);
}

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
