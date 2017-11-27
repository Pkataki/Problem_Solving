#include<bits/stdc++.h>
using namespace std;
int v[100005];
int vis[100005];
set<pair<int,int> >s;
vector<int> graph[100005];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
		s.insert(make_pair(-v[i],i));
	}
	while(m--)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int ans = 0;
	while(s.size())
	{
		pair<int,int>at = *s.begin();
		vis[at.second] = 1;
		s.erase(at);
		for(int i = 0; i < graph[at.second].size(); i++)
		{
			if(!vis[graph[at.second][i]])
				ans += v[graph[at.second][i]];
		}
	}
	cout << ans << '\n';
}
