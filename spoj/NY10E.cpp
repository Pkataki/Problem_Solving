#include<bits/stdc++.h>
using namespace std;
long long dp[70][11];
int main()
{
	for(int i = 0 ; i < 10; i++)
		dp[0][i] = 1;
	for(int i = 1; i<= 64; i++)
	{
	
		for(int j = 0 ; j < 10; j++)
		{
			for(int k = 0 ; k <= j ; k++)
			{
				dp[i][j] += dp[i-1][k];
			}
		}
	}
	int test;
	cin >> test;
	while(test--)
	{
		int a,b;
		cin >> a >> b;
		cout << a << ' ' << dp[b][9] << '\n';
	}

	return 0;
}
