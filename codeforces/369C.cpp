#include<bits/stdc++.h>
using namespace std;
int dp[200005];
int pr[200005];
bool vis[200005];
vector<int>graph[200005];
void dfs(int u, int parent)
{
	if(vis[u])
		return;
	vis[u] = 1;
	dp[u] += pr[u];
	for(int i = 0; i < graph[u].size(); i++)
	{
		if(graph[u][i] != parent && !vis[graph[u][i]])
		{
			dfs(graph[u][i],u);
			dp[u] += dp[graph[u][i]];
		}	
	}
}	
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i < n; i++)
	{
		int u,v,t;
		scanf("%d %d %d",&u,&v,&t);
		graph[u].push_back(v);
		graph[v].push_back(u);
		if(t == 2)
		{
			pr[u] = pr[v] = 1;
		}
	}
	dfs(1,1);
	vector<int>ans;
	for(int i = 1; i <= n; i++)
	{
		if(pr[i] && dp[i] == 1)
			ans.push_back(i);
	}
	printf("%d\n",(int)ans.size());
	for(int i = 0; i < ans.size(); i++)
	{
		if(i)
			printf(" ");
		printf("%d",ans[i]);
	}
	puts("");
}
