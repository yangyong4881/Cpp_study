#pragma once
#include"clock.h"
#include"Date.h"

class ClockWithDate : public Clock,public Date{
public:
	ClockWithDate(int h, int m, int s, int day, int month, int year);
	void run();
	void showTime();
};

