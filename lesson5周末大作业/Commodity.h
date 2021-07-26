#pragma once
#include<iostream>
#include<string>
using namespace std;
class Commodity
{
public:
	string type;      //种类
	string name;   //名称
	double price;  //价格
	int count;     //数量
public:
	 virtual void myPrint() = 0;
};


