#include<iostream>

using namespace std;

int main()
{
	unsigned int n;
	cin >> n;
	int c, m = 0, s[100];
	while (n!=0)
	{
		c = n % 16;
		n /= 16;
		m++;
		s[m] = c;
	}
	for (int i = m; i >= 1; i--)
	{
		if (s[i] > 9) cout << (char)(s[i] + 55);
		else cout << s[i];
	}
	return 0;
}