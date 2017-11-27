#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100005];
int b[100005];
int a[100005];
vector<int>ans;
int dfs(int v, int p, int e, int o)
{
	if((a[v] ^ e ) != b[v])
	{
		ans.push_back(v);
		e ^= 1;
	}
	for(int i = 0; i < graph[v].size(); i++)
	{
		if(p != graph[v][i])
			dfs(graph[v][i], v, o, e);
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i < n ; i++)
	{
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1; i <= n; i++)
		cin >> b[i];
	dfs(1,-1,0,0);
	cout << ans.size() << '\n';
	for(int i= 0; i < ans.size() ; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
