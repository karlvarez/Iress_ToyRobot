#pragma once

#include "Global.h"

/*
* current position, x and y coordinates of the Robot and the direction it is facing
*/
typedef struct tagPosition {
	long x;
	long y;
	Face face;
} Position;

// initial value for Position.x and Position.y, meaning Robot has not yet been placed on the table
#define POS_NOTSET -1

/* TODO: (Nice-to-have) move strings to rc */
#define S_FACE_N "North"
#define S_FACE_E "East"
#define S_FACE_W "West"
#define S_FACE_S "South"

class Robot
{
private:
	Position m_pos;

	// set the X position of the Robot
	void SetX(long);

	// set the Y position of the Robot
	void SetY(long);

	// set the direction that the Robot is facing
	void SetFace(Face);

	// check if the Robot is in a valid position i.e. Place command has been issued
	bool isValidPos();

	// check if the Robot's new position will be valid if a certain command was processed e.g. Move
	bool isValidNewPos(long, long, long, long, long, long, Face);

public:
	// get the X position of the Robot
	long GetX();

	// get the Y position of the Robot
	long GetY();

	// get the direction that the robot is facing
	Face GetFace();

	// check if Placing the robot will result in a valid position and face
	bool TryPlace(long, long, long, long, long, long, Face);

	// actually place the Robot
	void Place(long, long, Face);

	// check if Moving the robot (1 unit along the direction it is facing) will result in a valid position
	bool TryMove(long, long, long, long);

	// actually move the robot (1 unit along the direction it is facing)
	void Move();

	// change the direction the robot is facing, 90 degrees to the Left or Counter-Clockwise, relative to where it is currently facing
	bool Left();

	// change the direction the robot is facing, 90 degrees to the Right or Clockwise, relative to where it is currently facing
	bool Right();

	// display the current position of the robot and the direction that the robot is facing
	void Report();

	Robot();
	~Robot();
};
