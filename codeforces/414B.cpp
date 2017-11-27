#include<bits/stdc++.h>
using namespace std;
int dp[2005][2002];
const int mod = 1000000007;
int main()
{
	int n,k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		dp[1][i] = 1;
	for(int i = 2; i <= k; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int l = j; l <= n; l += j)
			{
				dp[i][l] = (dp[i][l] + dp[i-1][j]) % mod;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans += dp[k][i];
		ans %= mod;
	}
	cout << ans << '\n';

}
