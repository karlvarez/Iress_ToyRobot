#include "Global.h"

#pragma once

/* TODO: (Nice-to-have) move strings to rc */
#define S_FACE_N "North"
#define S_FACE_E "East"
#define S_FACE_W "West"
#define S_FACE_S "South"

class Robot
{
private:
	Position m_pos;

	void SetX(long);
	void SetY(long);
	void SetFace(Face);
	bool isValidPos();
	bool isValidNewPos(long, long, long, long, long, long, Face);

public:
	long GetX();
	long GetY();
	Face GetFace();

	bool TryPlace(long, long, long, long, long, long, Face);
	void Place(long, long, Face);
	bool TryMove(long, long, long, long);
	void Move();
	bool Left();
	bool Right();
	void Report();

	Robot();
	~Robot();
};
