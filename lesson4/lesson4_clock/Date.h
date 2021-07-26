#pragma once
#include<iostream>
using namespace std;


class Date {
public:
	Date(int d=1,int m =1,int y = 1996)
	{
		if (m > 12 || m < 1)
		{
			m = 1;
		}
		if (d > days(y, m))
		{
			day = 1;
		}
		day = d;
		year = y;
		month = m;
	};
	int days(int year, int month);
	void NewDay();
	void showTime()
	{
		cout << year << "-" << month << "-" << day << endl;
	}
protected:
	int year;
	int month;
	int day;
};
