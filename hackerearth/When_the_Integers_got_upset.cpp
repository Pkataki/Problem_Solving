#include<bits/stdc++.h>
using namespace std;
int dp[12][12][1 << 12];
int p[12];
int v[12];
int n;
int solve(int last, int s_last, int mask)
{	
	int pos = __builtin_popcount(mask);
	if(pos == n || __builtin_popcount(mask) == n)
		return 0;
	if(dp[last][s_last][mask] != -1)
		return dp[last][s_last][mask];

	int ans = INT_MAX;
	for(int i = 0; i < n; i++)
	{
		if(mask & (1 << i))
			continue;
		ans = min(ans, (v[i]^v[last]^v[s_last])*p[pos] + solve(i,last,mask|(1 << i)));
	}
	return dp[last][s_last][mask] = ans;
}
main()
{
	int test;
	cin >> test;
	while(test--)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> v[i];
		for(int i = 0; i < n; i++)
			cin >> p[i];
		int ans = (1<< 30);
		memset(dp,-1,sizeof(dp));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int f = (1 << i);
				int s = (1 << j);
				int mask = (f|s);
				ans = min(ans,solve(i,j,mask));
			}
		}
		cout << ans << "\n";
	}
}
