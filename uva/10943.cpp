#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	while(cin >> n >> k && (n+k) != 0)
	{
		long long dp[150][150];
		memset(dp,0,sizeof(dp));
		for(int i = 0 ; i<= n; i++)
			dp[n][1] = 1;
		const int MOD = 1000000;
		
		for(int i = 2 ; i <= k ; i++)
		{
			for(int j =  0; j <= n ; j++)
			{
				for(int l = 0; l <= n ; l++)
				{
					dp[n][k] = (dp[n][k] + dp[n-l][k-1]) % MOD;
				}
			}
		}
		cout << dp[n][k] << '\n';
	}
	return 0;
}
