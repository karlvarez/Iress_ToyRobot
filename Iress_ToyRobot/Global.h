#pragma once

/* global definitions */

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
