#include "Table.h"

#define ORIGIN_X 0
#define ORIGIN_Y 0

Table::Table() {
}

Table::~Table() {
}

void Table::SetSize(long xsize, long ysize) {
	m_xsize = xsize;
	m_ysize = ysize;
}

bool Table::PlaceRobot(long x, long y, Face face) {
	bool bRet = false;

	if (m_Robot1.TryPlace(x, ORIGIN_X, m_xsize - 1, y, ORIGIN_Y, m_ysize - 1, face)) {
		m_Robot1.Place(x, y, face);
		bRet = true;
	}

	return bRet;
}

bool Table::MoveRobot() {
	bool bRet = false;

	if (m_Robot1.TryMove(ORIGIN_X, m_xsize - 1, ORIGIN_Y, m_ysize - 1)) {
		m_Robot1.Move();
		bRet = true;
	}

	return bRet;
}

bool Table::LeftRobot() {
	return m_Robot1.Left();
}

bool Table::RightRobot() {
	return m_Robot1.Right();
}

void Table::ReportRobot() {
	m_Robot1.Report();
}

long Table::GetXSize() {
	return m_xsize;
}

long Table::GetYSize() {
	return m_ysize;
}