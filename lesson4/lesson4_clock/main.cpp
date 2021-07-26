#include<iostream>
#include"clock.h"
#include"Date.h"
#include"ClockWithDate.h"

using namespace std;

int main()
{
	int h, m, s, day, month, year;
	cout << "请输入时间:小时/分钟/秒  日-月-年" << endl;
	cin >> h >> m >> s >> day >> month >> year;
	ClockWithDate cd1(h, m, s, day, month, year);
	cout << "该月一共有" << cd1.days(year, month) << "天" << endl;
	cd1.showTime();
	cout << "现在运行x秒:";
	int x;
	cin >> x;
	for (int i = 0; i < x; ++i)
		cd1.run();
	cd1.showTime();
	return 0;
}