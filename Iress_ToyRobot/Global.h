#pragma once

/* global definitions */

/* constants */

#define TABLE_SIZE_X 5
#define TABLE_SIZE_Y 5

/* Face or Direction values corresponding to North, South, East, West
 * + NOTSET, meaning Robot has not yet been placed on the table
*/
typedef enum tagFace {
	FACE_NOTSET = -1,
	FACE_N = 0,
	FACE_E,
	FACE_W,
	FACE_S
} Face;

