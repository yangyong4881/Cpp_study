#include "ClockWithDate.h"

ClockWithDate::ClockWithDate(int h, int m, int s, int day, int month, int year) :Clock(h,m,s),Date(day,month,year){

}


void ClockWithDate::run() {
	if (second == 59) {
		if (minute == 59) {
			if (hour == 23) {
				hour = 0;
				minute = 0;
				second = 0;
				this->NewDay();
			}
			else {
				hour++;
				minute = 0;
				second = 0;
			}
		}
		else {
			minute++;
			second = 0;
		}
	}
	else {
		second++;
	}
}
void ClockWithDate::showTime() {
	cout << "Now:" << hour << ":" << minute << ":" << second << "  " << year << "-" << month << "-" << day << endl;
}