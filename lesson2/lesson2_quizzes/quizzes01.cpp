#include<iostream>
using namespace std;

template<typename T>
int compare(T a, T b)
{	
	if (a < b) return -1;
	if (b < a) return 1;
	return 0;
}

int text01()
{
	int a = 1;
	int b = 2;
	int res = compare(a, b);
	cout << res << endl;
	return 0;
}
int text02()
{
	char c = 'c';
	char d = 'b';
	int res = compare(c, d);
	cout << res << endl;
	return 0;
}
int main()
{
	text01();
	text02();
	/*unsigned long n = 1024 * 1024 * 1024;
	char* res = new char[n];
	delete[] res;*/
	return 0;
}