//#include <iostream>
//using namespace std;
//// 在此处补充你的代码
//class animal
//{
//public:
//	static int number;
//	animal() {
//		number++;
//	}
//	virtual ~animal()
//	{
//		number--;
//	}
//};
//
//class dog: public animal
//{
//public:
//	static int number;
//	dog() {
//		number++;
//	}
//	~dog()
//	{
//		number--;
//	}
//};
//
//class cat : public animal
//{
//public:
//	static int number;
//	cat() {
//		number++;
//	}
//	 ~cat()
//	{
//		number--;
//	}
//};
//int animal::number = 0, dog::number = 0, cat::number = 0;
//void print() {
//	cout << animal::number << " animals in the zoo, " << dog::number << " of them are dogs, " << cat::number << " of them are cats" << endl;
//}
//
//int main() {
//	print();
//	dog d1, d2;
//	cat c1;
//	print();
//	dog* d3 = new dog();
//	animal* c2 = new cat;
//	cat* c3 = new cat;
//	print();
//	delete c3;
//	delete c2;
//	delete d3;
//	print();
//}

//#include <iostream> 
//using namespace std;
//class A
//{
//public:
//	A() { }
//	// 在此处补充你的代码
//	virtual ~A()
//	{
//		cout << "`A" << endl;
//	}
//};
//class B :public A {
//public:
//	~B() { cout << "destructor B" << endl; }
//};
//int main()
//{
//	A* pa;
//	pa = new B;
//	delete pa;
//	return 0;
//}

//#include <iostream> 
//using namespace std;
//class A {
//private:
//	int nVal;
//public:
//	void Fun()
//	{
//		cout << "A::Fun" << endl;
//	};
//	 virtual void Do()
//	{
//		cout << "A::Do" << endl;
//	}
//};
//class B :public A {
//public:
//	virtual void Do()
//	{
//		cout << "B::Do" << endl;
//	}
//};
//class C :public B {
//public:
//	void Do()
//	{
//		cout << "C::Do" << endl;
//	}
//	void Fun()
//	{
//		cout << "C::Fun" << endl;
//	}
//};
//void Call(A &p
//	// 在此处补充你的代码
//) {
//	p.Fun(); p.Do();
//}
//int main() {
//	C c;
//	Call(c);
//	return 0;
//}

#include <iostream>

using namespace std;

class Animal {
public:
	int age;
//private:
//	int age;
};
class dog : public Animal {
public:
	void setAge(int n)
	{
		age = n;
	}
};

int main()
{
	dog d1;

	return 0;
}