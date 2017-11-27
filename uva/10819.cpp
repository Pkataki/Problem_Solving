#include<bits/stdc++.h>
using namespace std;
int n,w;
long long dp[10205][125];
pair<int,int>v[105];
long long solve(int pos, int peso)
{
	if(pos == n)
	{
		int d = w + 200 - peso;
		if(d > w && d <= 2000)
			return INT_MIN;

		return 0;
	}
	if(~dp[peso][pos])
		return dp[peso][pos];
	
	long long &ans = dp[peso][pos];
	ans = 0;
	ans += solve(pos+1,peso);
	if(peso - v[pos].first >= 0)
	{
		ans = max(ans, solve(pos+1,peso-v[pos].first) + (long long)v[pos].second);
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	while(cin >> w >> n)
	{
		memset(dp,-1,sizeof(dp));
		for(int i = 0; i < n; i++)
		{
			cin >> v[i].first >> v[i].second;
		}
		cout << solve(0,w+200) << '\n';
	}
	return 0;
}
