#include <bits/stdc++.h>
using namespace std;
int dp[13][100];
int main()
{
	for(int i = 0; i<= 12; i++)
	{
		dp[i][0] = 1;
	}
	for(int i = 2; i <= 12; i++)
	{
		for(int j = 0; j <= 98; j++)
		{
			if(j <= i)
			dp[i][j] += dp[i-1][j];
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	int n,k;
	cin >> n >> k;
	cout << dp[n][k] << '\n';
	return 0;
}
