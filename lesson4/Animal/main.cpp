#include<iostream>
#include<vector>
#include"Animal.h"
#include"Cat.h"
#include"Dog.h"

using namespace std;

int main()
{
	int N;
	cout << "请输入一个大于0的整数N！" << endl;
	cin >> N;
	vector<Animal*> v;
	for (int i = 0; i < N; i++) {
		v.push_back(new Dog);
		v.push_back(new Cat);
	}
	for (int i = 0; i < v.size(); i++)
	{
		v[i]->speak();
		if (Dog* dog = dynamic_cast<Dog*>(v[i]))
		{
			dog->swim();
		}
		delete v[i];
		v[i] = nullptr;
	}
	return 0;
}