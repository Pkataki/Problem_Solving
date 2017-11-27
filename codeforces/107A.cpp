#include<bits/stdc++.h>
using namespace std;
bool not_tank[1005];
vector<pair<int,int> >graph[1005];
bool vis[1005];
vector<pair < int, pair<int,int> > > ans;
void dfs(int u, int p, int f, int cap)
{
	vis[u] = 1;
	if(u == f && cap != INT_MAX)
		return;
	if(graph[u].size() == 0)
	{
		ans.push_back({f,{u,cap}});
		return ;
	}
	for(int i  = 0 ; i < graph[u].size(); i++)
	{
		int v = graph[u][i].first;
		if(!vis[v] && v != p)
		{
			dfs(v,u,f,min(cap,graph[u][i].second));
		}
	}
}
bool ap[1005];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i= 0; i < m; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b,c));
		not_tank[b] = 1;
		ap[a] = ap[b] = 1; 
	}
	for(int i = 1; i <= n; i++)
	{
		memset(vis,0,sizeof(vis));
		if(ap[i] && !not_tank[i] && graph[i].size() > 0)
		{
			dfs(i,-1,i,	INT_MAX);
		}
	}
	cout << ans.size() <<'\n';
	for(int i= 0 ; i < ans.size(); i++)
	{
		cout << ans[i].first << ' ' << ans[i].second.first << ' ' << ans[i].second.second << '\n';  
	}
	return 0;
}
