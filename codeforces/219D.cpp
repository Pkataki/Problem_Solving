#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int> > graph[200005];
int dfs1(int v, int p)
{
	int ans = 0;
	for(int i = 0; i < graph[v].size(); i++)
	{
		if(graph[v][i].first != p)
			ans += dfs1(graph[v][i].first, v) + graph[v][i].second;
	}
	return ans;
}
vector<int>ans1;
int best;
void dfs2(int v, int p, int val)
{
	if(best > val)
	{
		ans1.clear();
		best = val;
	}
	if(best == val)
		ans1.push_back(v);
	
	for(int i = 0 ; i < graph[v].size(); i++)
	{
		if(graph[v][i].first != p)
		{
			dfs2(graph[v][i].first,v,val +  (graph[v][i].second ? -1 : 1));
		}
	}
}
int main()
{
	cin >> n;
	for(int i = 0; i < n-1; i++)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(make_pair(b,0));
		graph[b].push_back(make_pair(a,1));
	}
	best = 0x3f3f3f3f;
	int aux = dfs1(1,1);
	dfs2(1,1,aux);
	cout << best << '\n';
	sort(ans1.begin(),ans1.end());
	cout << ans1[0];
	for(int i = 1; i < ans1.size(); i++)
		cout << ' ' << ans1[i];
	cout << endl;
}

