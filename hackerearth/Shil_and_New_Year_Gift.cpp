#include<bits/stdc++.h>
using namespace std;
long long dp[16][1 << 16 + 1];
int n;
int v[16];
long long solve(int pos, int mask)
{
	if(pos == n || __builtin_popcount(mask) == n)
	{
		return 0;
	}
	if(dp[pos][mask] != -1LL)
	{
		return dp[pos][mask];
	}
	dp[pos][mask] = 0LL;
	long long ans = 0LL;
	for(int i = 0; i < n; i++)
	{
		if(!(mask & (1 << i)))
			ans = max(ans,solve(i, mask | (1 << i)) + __gcd(v[i],v[pos]));
	}
	return dp[pos][mask] = ans;
}
main()
{
	ios_base::sync_with_stdio(false);
	memset(dp,-1,sizeof(dp));
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	long long ans = 0LL;
	for(int i = 0; i < n; i++)
	{
		int mask = 0;
		ans = max(ans, solve(i,mask | (1 << i)));
	}
	cout << ans << "\n";
}
