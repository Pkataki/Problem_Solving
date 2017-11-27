#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >graph[7];
int dp[10][1005];
int solve(int item, int money)
{
	if(money < 0)
		return 0;
	if(item > 6)
		return INT_MAX;
	if(dp[item][money] != -1)
		return dp[item][money];
	int ans = 0;
	dp[item][money] = 0;
	for(int i = 0 ; i < graph[item].size(); i++)
	{
		if(money >= graph[item][i].first)
		{
			ans = max(ans,min(graph[item][i].second , solve(item+1,money-graph[item][i].first)));
		}
	}
	return dp[item][money] = ans;
}
int main()
{
	int n,t;
	cin >> n >> t;
	memset(dp,-1,sizeof(dp));
	for(int i = 0 ; i < n ; i++)
	{
		int typ,p,q;
		cin >> typ >> p >> q;
		graph[typ].push_back(make_pair(p,q));
	}
	cout << solve(1,t) << '\n';
	return 0;
}
