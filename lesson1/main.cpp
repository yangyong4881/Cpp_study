#include<iostream>

using namespace std;

int solution(int m, int n)
{
	int dp[100][100];
	if (m < 1 && n < 1) return 0;
	for (int i = 0; i <= m; i++)
	{
		dp[i][0] = 1;
	}
	for (int j = 0; j <= n; j++)
	{
		dp[0][j] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m][n];
}


int main()
{
	int m, n;
	cin >> m >> n;
	int res = solution(m, n);
	cout << res << endl;
	return 0;
}
