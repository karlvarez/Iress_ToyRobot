#pragma once

/* global definitions */

/* constants */

#define TABLE_SIZE_X 5
#define TABLE_SIZE_Y 5

/* Commands */
typedef enum tagCommand {
	COMM_UNSUPPORTED = -1,
	COMM_PLACE = 0,
	COMM_MOVE,
	COMM_LEFT,
	COMM_RIGHT,
	COMM_REPORT
} Command;

/* Position */
#define POS_NOTSET -1

/* Face or Direction */
typedef enum tagFace {
	FACE_NOTSET = -1,
	FACE_N = 0,
	FACE_E,
	FACE_W,
	FACE_S
} Face;

typedef struct tagPosition {
	long x;
	long y;
	Face face;
} Position;
