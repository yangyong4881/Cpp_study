#include<iostream>
using namespace std;

template<typename T>
void mySwap(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
int partition(T v, int begin, int end)
{	
	int pivot = v[begin];
	int l = begin + 1;
	int r = end;
	while (l <= r)
	{
		while (l <= r && v[l] <= pivot) l++;
		while (l <= r && v[r] > pivot) r--;
		if (v[l] < v[r])
		{
			mySwap(v[l], v[r]);
			/*int tmp = v[l];
			v[l] = v[r];
			v[r] = tmp;*/
		}
	}
	mySwap(v[begin], v[r]);
	return r;
}
template<typename T>
void quickSort(T v,int begin,int end)
{
	if (begin < end)
	{
		int q = partition(v, begin, end);
		quickSort(v, begin, q - 1);
		quickSort(v, q + 1, end);
	}
}

int main() 
{
	int v[7] = { 6,1,3,2,5,7,9 };
	quickSort(v, 0, 6);
	for (int i = 0; i < 7; i++) 
	{
		cout << v[i];
	}
	return 0;
}