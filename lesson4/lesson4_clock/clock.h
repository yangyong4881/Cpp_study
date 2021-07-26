#pragma once
#include<iostream>
using namespace std;

//bool leap(int year)
//{
//	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
//		return true;
//	return false;
//}
class Clock {
public:
	Clock(int h, int m, int s)
	{
		hour = (h > 23 ? 0 : h);
		minute = (m > 59 ? 0 : m);
		second = (s > 59 ? 0 : s);
	}
	virtual void run()
	{
		second = second + 1;
		if (second > 59)
		{
			second = 0;
			minute += 1;
		}
		if (minute > 59)
		{
			minute = 0;
			hour += 1;
		}
		if (hour > 23)
		{
			hour = 0;
		}
	}
	virtual void showTime()
	{
		cout << "Now:" << hour << ":" << minute << ":" << second << endl;
	}
	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }


protected:
	int hour;
	int minute;
	int second;
};