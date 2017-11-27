#include<bits/stdc++.h>
using namespace std;
long long dp[1000000];
main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int coins[m];
	for(int i = 0; i < m; i++)
		cin >> coins[i];
	dp[0] =  1; 
	for(int i = 0; i < m; i++)
	{
		for(long long j = coins[i]; j <= n; j++)
		{
			dp[j] += dp[j - coins[i]];
		}
	}
	cout << dp[n] << "\n";
}
