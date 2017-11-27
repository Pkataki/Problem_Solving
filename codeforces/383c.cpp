#include<bits/stdc++.h>
using namespace std;
vector<int>graph[101];
int ans;
map<int,bool>m;
void dfs(int u, int cont)
{
	if(m.count(u))
	{
		ans = min(ans,cont);
		return;
	}
	m[u] = 1;
	for(int i = 0; i < graph[u].size(); i++)
	{
		dfs(graph[u][i],cont+1);	
	}
}
main()
{
	int n;
	cin >> n;
	vector<int>v;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
		graph[i+1].push_back(a);
	}
	ans = INT_MAX;
	for(int i = 0; i < v.size(); i++)
	{
		m.clear();
		dfs(i+1,0);
	}
	cout << ans << "\n";
}
