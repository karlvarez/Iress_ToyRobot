#include "Global.h"

#pragma once

/* TODO: (Nice-to-have) move strings to rc */
#define S_FACE_N "North"
#define S_FACE_E "East"
#define S_FACE_W "West"
#define S_FACE_S "South"

#define POS_NOTSET -1


class Robot
{
private:
	long m_xpos = POS_NOTSET;
	long m_ypos = POS_NOTSET;
	Face m_face = FACE_NOTSET;

	void setX(long);
	void setY(long);
	void setFace(Face);

public:
	int getX();
	int getY();
	Face getFace();

	void Place(long, long, Face);
	void Move();
	void Left();
	void Right();
	void Report();

	Robot();
	~Robot();
};
