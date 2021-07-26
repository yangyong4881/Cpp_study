#include"Vec2D.h"


Vec2D::Vec2D() {
	n = 0.0;
	m = 0.0;
}

Vec2D::Vec2D(double nVal, double mVal) {
	n = nVal;
	m = mVal;
}

Vec2D::~Vec2D(){}

string Vec2D::toString() {
	string N = to_string(n);
	string M = to_string(m);
	return '(' + N + ", " + M + ')';
}

Vec2D Vec2D::operator+(const Vec2D& secondVec2D) {
	return Vec2D(n + secondVec2D.n, m + secondVec2D.m);
}

Vec2D Vec2D::operator+(double number) {
	return Vec2D(this->n + number, this->m + number);
}
Vec2D Vec2D::operator+=(const Vec2D& secondVec2D) {
	return Vec2D(n += secondVec2D.n, m += secondVec2D.m);
}

Vec2D Vec2D::operator-(const Vec2D& secondVec2D) {
	return Vec2D(this->n - secondVec2D.n, this->m - secondVec2D.m);
}

Vec2D Vec2D::operator-=(const Vec2D& secondVec2D) {
	return Vec2D(n -= secondVec2D.n, m -= secondVec2D.m);
}

//点积
double Vec2D::operator*(const Vec2D& secondVec2D) {
	return (n * secondVec2D.n+ m * secondVec2D.m);
}
//数乘
Vec2D Vec2D::operator*(double number){
	return Vec2D(n * number, m * number);
}
Vec2D operator*(double number,Vec2D vec2d){
	return (vec2d * number);
}

Vec2D Vec2D::negative() {
	return Vec2D(-n, -m);
}
Vec2D Vec2D::operator-() {
	return Vec2D(-n, -m);
}

Vec2D& Vec2D::operator++() {
	n++; m++;
	return *this;
}
Vec2D Vec2D::operator++(int dummy){
	Vec2D tmp(*this);
	n++; m++;
	return tmp;
}

Vec2D& Vec2D::operator--() {
	n--; m--;
	return *this;
}
Vec2D Vec2D::operator--(int dummy){
	Vec2D tmp(*this);
	n--; m--;
	return tmp;
}

double& Vec2D::operator[](const int& index) {
	if (0 == index) return n;
	else if (1 == index) return m;
	else cout << "请选择0或1的索引" << endl;
}

double Vec2D::magnitude() {
	return sqrt(n * n + m * m);
}
Vec2D::operator double() {
	return this->magnitude();
}
double Vec2D::direction() {
	return atan(m / n);
}

int Vec2D::compareTo( Vec2D& secondVec2D) {
	if (this->magnitude() > secondVec2D.magnitude()) return 1;
	else return -1;
}

ostream& operator<<(ostream& os,const Vec2D& secondVec2D) {
	
	os << "(" << secondVec2D.n << ", " << secondVec2D.m << ")";
	return os;
}
istream& operator>>(istream& is, Vec2D& secondVec2D) {
	is >> secondVec2D.n >> secondVec2D.m;
	return is;
}