#include<iostream>
#include"KsoString.h"

using namespace std;

int main()
{
	KsoString<char> K;
	KsoString<wchar_t> K1;
	K1.push_back('a'); 
	K1.push_back('b'); 
	K1.push_back('c');
	K.push_back('a');
	//K1.print();
	K.push_back('b');
	K.push_back('c');
	K.pop_front();
	K.push_back('f');
	K.push_back('e');
	//K.push_back("fffff");
	K.push_back('h');
	K.show();
	cout << "K中元素个数为：" << K.GetSize() << endl;
	K.insert(5, 'c');
	K.erase(3);
	K.show();
	cout << K[1] << endl;
	return 0;
}