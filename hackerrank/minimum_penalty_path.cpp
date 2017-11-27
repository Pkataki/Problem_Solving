#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int > > >graph(1005);
int dist[1005];
int vis[1005];
main()
{
	memset(dist,0x3f3f3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	int inf = dist[0];
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b,c));		
		graph[b].push_back(make_pair(a,c));		
	}
	int ini,fim;
	cin >> ini >> fim;
	priority_queue<pair<int,int> >pq;
	pq.push(make_pair(0,ini));
	dist[ini] = 0;
	vis[ini] = 1;
	int ans = (1 << 28);
	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int at = pq.top().second;
		pq.pop();
		vis[at] = 1;
		if(at == fim)
			ans = min(ans,cost);
	
		for(int i = 0; i < graph[at].size(); i++)
		{
			int v = graph[at][i].first;
			int c = graph[at][i].second;
			if(vis[v])
				continue;
			if(dist[at]|c < dist[v])
			{
				dist[v] = dist[at]|c;
				pq.push(make_pair(-dist[v],v));
			}
		}
	}
	if(dist[fim] == inf)
	{
		cout << "-1\n";
	}
	else
		cout << ans << "\n";

	
}
