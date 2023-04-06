#include "Table.h"


#define ORIGIN_X 0
#define ORIGIN_Y 0

Table::Table() {
}

Table::~Table() {
}

/*
* Set the dimensions of the table
* 
* Parameters:
*   xsize       : number of units in the horizontal direction
*   ysize       : number of units in the vertical direction
*/
void Table::SetSize(long xsize, long ysize) {
    m_xsize = xsize;
    m_ysize = ysize;
}

/*
* Try placing the robot on the coordinates provided.
* If placing the robot will cause and invalid position/face, do not proceed.
* Otherwise, proceed with actually placing the robot.
* 
* Parameters:
*   x           : x coordinate where the robot will be placed
*   y           : y coordinate where the robot will be placed
*   face        : the direction the robot would be facing
* 
* Return value:
*   true        : sucessfully placed the robot
*   false       : unable to place the robot
*/
bool Table::PlaceRobot(long x, long y, Face face) {
    bool bRet = false;

    // call TryPlace() to check if placing the robot will result in invalid or not
    // send the x, y and face along with the allowed min and max x and y coordinates
    if (m_Robot1.TryPlace(x, ORIGIN_X, m_xsize - 1, y, ORIGIN_Y, m_ysize - 1, face)) {
        // if TryPlace() succeeded, proceed with actually placing the robot
        m_Robot1.Place(x, y, face);
        bRet = true;
    }

    return bRet;
}

/*
* Try moving the robot.
* If moving the robot will cause and invalid position, do not proceed.
* Otherwise, proceed with actually moving the robot.
*
* Parameters:
*   none
*
* Return value:
*   true        : sucessfully moved the robot
*   false       : unable to moved the robot
*/
bool Table::MoveRobot() {
    bool bRet = false;

    // call TryMove() to check if moving the robot will result in invalid or not
    // send the allowed min and max x and y coordinates
    // no need to send x, y and face since the robot has those attributes already
    if (m_Robot1.TryMove(ORIGIN_X, m_xsize - 1, ORIGIN_Y, m_ysize - 1)) {
        // if TryMove() succeeded, proceed with actually moving the robot
        m_Robot1.Move();
        bRet = true;
    }

    return bRet;
}

/*
* Call robot's Left() function directly, no need for checking as it cannot result in invalid
*
* Return value:
*   true        : sucessfully turned the robot left
*   false       : unable to turn the robot left (impossible in current implementation)
*/
bool Table::LeftRobot() {
    return m_Robot1.Left();
}

/*
* Call robot's Right() function directly, no need for checking as it cannot result in invalid
*
* Return value:
*   true        : sucessfully turned the robot right
*   false       : unable to turn the robot right (impossible in current implementation)
*/
bool Table::RightRobot() {
    return m_Robot1.Right();
}

/*
* Call robot's Report() function directly
*/
void Table::ReportRobot() {
    m_Robot1.Report();
}
