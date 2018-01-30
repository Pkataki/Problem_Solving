#include<bits/stdc++.h>
using namespace std;
const int MAXN = 80;
int dp[MAXN][MAXN][4];
int vis[MAXN][MAXN][4];
vector<pair<int,int> >graph[80], g[80];
int vi = 0;
int solve(int i, int pai, int k, int np)
{
	if(graph[pai].size() == i )
	{
		return 0;
	}
	
	int v = graph[pai][i].first;
	int cost = graph[pai][i].second;
	
	int &ans = dp[v][k][np];
	
	
	if(vis[v][k][np] == vi)
		return dp[v][k][np];
	vis[v][k][np] = vi;
	
	ans = solve(i+1, pai, k , np);
	
	for(int k1 = 0; k1 <= k; k1++)
	{
		if(np == 1)
			ans = max(ans , solve(i+1, pai, k - k1, 2) + solve(0,v,k1,1) + cost);
		if(!np && k1)
			ans = max(ans , solve(i+1, pai, k - k1, 1) + solve(0,v,k1-1,1) + cost);
		
		ans = max(ans, solve(0, v, k1, 0) + solve(i+1, pai, k - k1, np) );	
	}
	return ans;
}
void dfs(int u, int pai)
{
	for(int i = 0 ; i < g[u].size(); i++)
	{
		int v = g[u][i].first;
		int c = g[u][i].second;
		if(v == pai)	
			continue;
		dfs(v,u);
		graph[u].push_back(make_pair(v,c));
	}
}
int main()
{
	int test;
	scanf("%d",&test);
	int n,k;
	while(test--)
	{
		vi++;
		for(int i = 1; i <= 70; i++)
		{
			graph[i].clear();
			g[i].clear();
		}
		scanf("%d %d",&n,&k);
		for(int i = 1 ; i < n ; i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			g[a].push_back(make_pair(b,c));
			g[b].push_back(make_pair(a,c));
		}
		dfs(1,1);
		printf("%d\n",solve(0,1,k,0));			
	}
	return 0;
}
