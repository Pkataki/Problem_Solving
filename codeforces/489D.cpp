#include<bits/stdc++.h>
using namespace std;
int cont[3005];
vector<int>graph[3005];
void dfs(int u, int d, int p)
{
	if(d == 2 )
	{
		cont[u] += 1;
		return ;
	}
	for(int i = 0; i < graph[u].size(); i++)
	{
		if(graph[u][i] == p)
			continue;
		dfs(graph[u][i], d+1, u);
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		memset(cont,0,sizeof(cont));
		dfs(i,0,-1);
		for(int j = 1; j <= n; j++)
		{
			if(i == j)
				continue;
			ans += (cont[j] * (cont[j] - 1)) / 2;
		}
	}
	cout <<ans << '\n';
	return 0;
}
