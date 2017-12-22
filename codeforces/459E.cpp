#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >weights[100005];
int dp[300005];
int tmp[300005];
int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m ; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		weights[c].push_back({a,b});
	}
	for(int i = 0; i < 100005; i++)
	{
		for(int j = 0; j < weights[i].size(); j++)
		{
			int u = weights[i][j].first;
			int v = weights[i][j].second;
			tmp[v] = max(tmp[v],dp[u] + 1);
		}
		for(int j = 0; j < weights[i].size(); j++)
		{
			int u = weights[i][j].first;
			int v = weights[i][j].second;
			dp[v] = max(tmp[v],dp[v]);
		}
		for(int j = 0; j < weights[i].size(); j++)
		{
			int u = weights[i][j].first;
			int v = weights[i][j].second;
			tmp[v] = 0;
			tmp[u] = 0;
		}
		
	}

	printf("%d\n", *max_element(dp,dp+n+1));
	return 0;
}
