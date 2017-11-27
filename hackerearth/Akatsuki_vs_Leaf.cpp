#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20][1 << 20];
int n;
vector<pair<ll,ll> >akatsuki(21);
vector<pair<ll,ll> >leaf(21);
ll dist(int pos1, int pos2)
{
	return llabs(leaf[pos1].first - akatsuki[pos2].first) + llabs(leaf[pos1].second - akatsuki[pos2].second);
}

ll solve(int pos, int mask)
{
	if(pos == n || __builtin_popcount(mask) == n)
	{
		return 0LL;
	}
	if(dp[pos][mask] != -1LL)
		return dp[pos][mask];
	ll ans = LLONG_MAX;
	dp[pos][mask] = LLONG_MAX;
	for(int i = 0; i < n; i++)
	{
		if(!(mask & (1 << i)))
		{
			ans = min(ans,solve( pos+1, (mask |(1<< i)) )+ dist(pos,i));
		}
	}
	return dp[pos][mask] = ans;
}

main()
{
	memset(dp,-1LL, sizeof(dp));
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> akatsuki[i].first >> akatsuki[i].second;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> leaf[i].first >> leaf[i].second;
	}
	cout << solve(0,0) << "\n";
}
