#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long MOD = 1000000007;	
	long long dp[200][200];
	int n,m;
	while(cin >> n >> m && n > 0 && m > 0)
	{
		dp[0][0] = 1LL;
		for(int i = 0 ; i <= n; i++)
		{
			for(int j = 0; j <= m ;j++)
			{
				
				if(i == 0 && j == 0)
					continue;
				dp[i][j] = 0LL;
				if(i-1 >= 0)
					dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
				if(j-1 >= 0)
					dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
			}
		}
		cout << dp[n][m] << '\n';
	}
	return 0;
}
