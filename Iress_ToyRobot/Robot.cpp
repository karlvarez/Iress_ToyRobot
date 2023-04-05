#include "Global.h"
#include "Robot.h"

#include <iostream>
#include <string>

Robot::Robot() {
	/* Constructor */
}

Robot::~Robot() {
	/* Destructor */

}

int Robot::getX() {
	return m_xpos;
}

int Robot::getY() {
	return m_ypos;
}

Face Robot::getFace() {
	return m_face;
}

void Robot::setX(long x) {
	m_xpos = x;
}
void Robot::setY(long y) {
	m_ypos = y;
}
void Robot::setFace(Face face) {
	m_face = face;
}

void Robot::Place(long x, long y, Face face)
{
	setX(x);
	setY(y);
	setFace(face);
}

void Robot::Move() {
	switch (m_face) {
	case FACE_N:
		setY(m_ypos + 1);
		break;
	case FACE_S:
		setY(m_ypos - 1);
		break;

	case FACE_E:
		setX(m_xpos + 1);
		break;
	case FACE_W:
		setX(m_xpos - 1);
		break;

	default:
		break;
	}
}

void Robot::Left() {
	switch (m_face) {
	case FACE_N:
		setFace(FACE_W);
		break;
	case FACE_S:
		setFace(FACE_E);
		break;

	case FACE_E:
		setFace(FACE_N);
		break;
	case FACE_W:
		setFace(FACE_S);
		break;

	default:
		break;
	}
}

void Robot::Right() {
	switch (m_face) {
	case FACE_N:
		setFace(FACE_E);
		break;
	case FACE_S:
		setFace(FACE_W);
		break;

	case FACE_E:
		setFace(FACE_S);
		break;
	case FACE_W:
		setFace(FACE_N);
		break;

	default:
		break;
	}
}

void Robot::Report() {
	/* TODO: remove calls to std output */

	if (m_xpos == POS_NOTSET ||
		m_ypos == POS_NOTSET ||
		m_face == FACE_NOTSET)
	{
		std::cout << "Invalid position or face, issue a valid PLACE command first";
		return;
	}

	std::string sFace;
	std::string sReport;

	switch (m_face) {
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

	sReport = "" + m_xpos;
	sReport += ", " + m_ypos;
	sReport += ", " + sFace;

	std::cout << sReport;
}
