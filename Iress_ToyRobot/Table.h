#include "Global.h"

#pragma once

#define SIZE_NOTSET -1

class Table
{
private:
	long m_xsize = SIZE_NOTSET;
	long m_ysize = SIZE_NOTSET;

public:
	bool isValidMove(long, long);

	Table(long, long);
	~Table();
};

