#pragma once

#include <iostream>
#include<cmath>
#include <exception>
#include<string>
using namespace std;

class Vec2D {
public:
	Vec2D();
	Vec2D(double, double);
	~Vec2D();
public:
	string toString();
	Vec2D add(const Vec2D&);
	Vec2D add(double);
	Vec2D operator+(const Vec2D&);
	Vec2D operator+(double);
	Vec2D operator+=(const Vec2D&);
	Vec2D operator-(const Vec2D&);
	Vec2D operator-=(const Vec2D&);
	double operator*(const Vec2D&);//µã»ý
	Vec2D operator*(double);
	friend Vec2D operator*(double, Vec2D);
	Vec2D negative();
	Vec2D operator-();
	Vec2D& operator++();
	Vec2D operator++(int);
	Vec2D& operator--();
	Vec2D operator--(int);
	double& operator[](const int&);
	double magnitude();
	operator double();
	double direction();
	int compareTo(Vec2D&);
	
	friend ostream& operator<<(ostream&, const Vec2D&);
	friend istream& operator>>(istream&, Vec2D&);

private:
	double n;
	double m;
};