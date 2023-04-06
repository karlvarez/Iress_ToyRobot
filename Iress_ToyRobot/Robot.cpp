#include "Global.h"
#include "Robot.h"

#include <iostream>

Robot::Robot() {
    /* Constructor */

    // set default position and face as NOTSET
    m_pos.x = POS_NOTSET;
    m_pos.y = POS_NOTSET;
    m_pos.face = FACE_NOTSET;
}

Robot::~Robot() {
    /* Destructor */

}

/*
* Get robot's current x coordinate
*
* Return value:
*   long        : robot's current x coordinate
*/
long Robot::GetX() {
    return m_pos.x;
}

/*
* Get robot's current y coordinate
*
* Return value:
*   long        : robot's current y coordinate
*/
long Robot::GetY() {
    return m_pos.y;
}

/*
* Get robot's current face i.e. direction it is facing
*
* Return value:
*   long        : robot's current face i.e. direction it is facing
*/
Face Robot::GetFace() {
    return m_pos.face;
}

/*
* Set robot's x coordinate
*
* Parameters:
*   x           : x coordinate to be set
*/
void Robot::SetX(long x) {
    m_pos.x = x;
}

/*
* Set robot's y coordinate
*
* Parameters:
*   y           : y coordinate to be set
*/
void Robot::SetY(long y) {
    m_pos.y = y;
}

/*
* Set robot's face i.e. direction it will be facing
*
* Parameters:
*   face           : face to be set
*/
void Robot::SetFace(Face face) {
    m_pos.face = face;
}

/*
* Check if executing a place command on x, y will result in a valid or invalid position
* 
* Parameters:
*   x           : x coordinate where the robot will be placed
*   xmin        : the minimum x position that is allowed
*   xmax        : the maximum x position that is allowed
*   y           : y coordinate where the robot will be placed
*   ymin        : the minimum y position that is allowed
*   ymax        : the maximum y position that is allowed
*   face        : the direction the robot would be facing
*
* Return value:
*   true        : executing the place command on x, y will result in a valid position
*   false       : ... will result in an invalid position e.g. robot falls off the table 
*/
bool Robot::TryPlace(long x, long xmin, long xmax, long y, long ymin, long ymax, Face face)
{
    bool bRet = isValidNewPos(x, xmin, xmax, y, ymin, ymax, face);
    return bRet;
}

/*
* Actually place the robot on x, y and facing the face supplied
*
* Parameters:
*   x           : x coordinate where the robot will be placed
*   y           : y coordinate where the robot will be placed
*   face        : the direction the robot would be facing
*/
void Robot::Place(long x, long y, Face face)
{
    SetX(x);
    SetY(y);
    SetFace(face);
}

/*
* Check if executing a move will result in a valid or invalid position
*
* Parameters:
*   xmin        : the minimum x position that is allowed
*   xmax        : the maximum x position that is allowed
*   ymin        : the minimum y position that is allowed
*   ymax        : the maximum y position that is allowed
*
* Return value:
*   true        : executing a move command will result in a valid position
*   false       : ... will result in an invalid position e.g. robot falls off the table
*/
bool Robot::TryMove(long xmin, long xmax, long ymin, long ymax) {
    bool bRet = false;

    // make sure the robot is on the table (has been placed successfully)
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

/*
* Move the robot 1 unit in the direction/face it is facing
*/
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

/*
* change the direction the robot is facing
* 90 degrees to the Left i.e. Counter-Clockwise relative to where it is currently facing
* 
* Return value:
*   true        : command was executed successfully.
*   false       : command failed. direction/face was not changed.
*/
bool Robot::Left() {
    bool bRet = false;

    // make sure the robot is on the table (has been placed successfully)
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

/*
* change the direction the robot is facing
* 90 degrees to the Right i.e. Clockwise relative to where it is currently facing
*
* Return value:
*   true        : command was executed successfully.
*   false       : command failed. direction/face was not changed.
*/
bool Robot::Right() {
    bool bRet = false;

    // make sure the robot is on the table (has been placed successfully)
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

/*
* display the current position of the robot and the direction that the robot is facing
*/ 
void Robot::Report() {
    /* TODO: remove calls to std output */

    if (!isValidPos())
    {
        std::cout << "Invalid position or face, issue a valid PLACE command first" << std::endl;
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

    std::cout << "Output: " << m_pos.x << "," << m_pos.y << "," << sFace << std::endl;
}

/*
* Checks if the robot is on the table (has been placed successfully)
* 
* Return value:
*   true        : current x, y and face are valid. robot has previosly been placed successfully.
*   false       : robot has not yet been placed on the table successfully.
*/
bool Robot::isValidPos() {
    return (m_pos.x != POS_NOTSET) &&
        (m_pos.y != POS_NOTSET) &&
        (m_pos.face != FACE_NOTSET);
}

/*
* Utility function used by TryPlace() and TryMove(); moved shared logic here for maintainability
* 
* Parameters:
*   see TryPlace()
* 
* Return value:
*   true        : new x, y and face are valid
*   false       : new x, y or face will be invalid, Place() or Move() will cause robot to fall
*/
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
