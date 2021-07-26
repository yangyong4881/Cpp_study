#include "Drinks.h"

//Drinks::Drinks() {
//	this->d_name = "NULL";
//	this->d_price = 0.0;
//	this->d_count = 0;
//}

Drinks::Drinks(string type,string name, double price, int count) {
	this->type = type;
	this->name = name;
	this->price = price;
	this->count = count;
}
//Drinks::Drinks(string name,double price, int count,string introduce) {
//	this->name = name;
//	this->price = price;
//	this->count = count;
//	this->introduce = introduce;
//}

void Drinks::myPrint() {
	cout << "[" << this->name << "($" << this->price << "),剩余" << this->count << "]";
}
int Drinks::operator<(Drinks& secondDrinks) {
	if (this->price < secondDrinks.price) return 1;
	else return -1;
}