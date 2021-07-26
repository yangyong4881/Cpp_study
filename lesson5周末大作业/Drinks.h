#pragma once
#include "Commodity.h"
#include <iostream>
#include <string>

using namespace std;
class Drinks :public Commodity{
public:
	Drinks(string, string, double, int);//构造函数

public:
	virtual void myPrint();//重写父类的打印函数
	int operator<(Drinks&);
};
