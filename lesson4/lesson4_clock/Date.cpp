#include "Date.h"

int Date::days(int year, int month) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
		//cout << year << "定" << month << "埖嗤31爺" << endl;
	}
	else if ((month == 2) && (year % 4 == 0)) return 29;//cout << year << "定" << month << "埖嗤29爺" << endl;
	else if ((month == 2) && (year % 4 != 0)) return 28;//cout << year << "定" << month << "埖嗤28爺" << endl;
	else  return 30;//cout << year << "定" << month << "埖嗤30爺" << endl;
}
void Date::NewDay() {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day < 31) {
			day++;
		}
		else if(month != 12){
			day = 1;
			month++;
		}
		else {
			day = 1;
			month = 1;
			year++;
		}
	}
	else if ((month == 2) && (year % 4 == 0)) {
		if (day < 29) {
			day++;
		}
		else {
			day = 1;
			month++;
		}
	}	
	else if ((month == 2) && (year % 4 != 0)) {
		if (day < 28) {
			day++;
		}
		else {
			day = 1;
			month++;
		}
	}
	else {
		if (day < 30) {
			day++;
		}
		else {
			day = 1;
			month++;
		}
	}
}