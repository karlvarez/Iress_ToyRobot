#pragma once

#include "Table.h"

/* constants */
// current requirements: 5x5 Table
// change these to resize the table or edit the Controller to manage/change the table size
#define TABLE_SIZE_X 5
#define TABLE_SIZE_Y 5

class Controller
{

private:
    // Controller class has 1 instance of Table
    Table m_table;

public:
    Controller();
    ~Controller();

    bool Place(long, long, Face);
    bool Move();
    bool Left();
    bool Right();
    void Report();

};

