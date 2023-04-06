#pragma once

/* global definitions */

/* Face or Direction values corresponding to North, South, East, West
 * NOTSET = Robot has not yet been placed on the table
*/
typedef enum tagFace {
    FACE_NOTSET = -1,
    FACE_N = 0,
    FACE_E,
    FACE_W,
    FACE_S
} Face;

