#include "Controller.h"


Controller::Controller() {
    // since the current requirements is a fixed-size table, it ok to set the size here using the Globally defined
    // table size, change this in case the table size is variable
    m_table.SetSize(TABLE_SIZE_X, TABLE_SIZE_Y);
}

Controller::~Controller() {
}


/*
* See the readme file, Controller at this point is more of a passthrough only
*/
bool Controller::Place(long x, long y, Face face) {
    bool bRet = false;

    if (m_table.PlaceRobot(x, y, face)) {
        bRet = true;
    }

    return bRet;
}

/*
* See the readme file, Controller at this point is more of a passthrough only
*/
bool Controller::Move() {
    bool bRet = false;

    if (m_table.MoveRobot()) {
        bRet = true;
    }

    return bRet;
}

/*
* See the readme file, Controller at this point is more of a passthrough only
*/
bool Controller::Left() {
    bool bRet = false;

    if (m_table.LeftRobot()) {
        bRet = true;
    }

    return bRet;
}

/*
* See the readme file, Controller at this point is more of a passthrough only
*/
bool Controller::Right() {
    bool bRet = false;

    if (m_table.RightRobot()) {
        bRet = true;
    }

    return bRet;
}

/*
* See the readme file, Controller at this point is more of a passthrough only
*/
void Controller::Report() {
    m_table.ReportRobot();
}
