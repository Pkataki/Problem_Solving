#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int > > >graph[1005];
int n,m;
double dist[1005];
double dijkstra(double t)
{
	for(int i = 1; i <= n; i++)
	{
		dist[i] = 1e12;
	}
	dist[1] = 0;
	priority_queue<pair<double,int> >q;
	q.push(make_pair(0.0,1));
	while(!q.empty())
	{
		double dis = -q.top().first;
		int at = q.top().second;
		q.pop();
		for(int i = 0; i < graph[at].size(); i++)
		{
			if(dist[graph[at][i].first] > dist[at] + (graph[at][i].second.first*t + graph[at][i].second.second) + 1e-9)
			{
				dist[graph[at][i].first] = dist[at] + (graph[at][i].second.first*t + graph[at][i].second.second);
				q.push(make_pair(-dist[graph[at][i].first],graph[at][i].first));
			}
		}
	}
	return dist[n];
}
main()
{
	ios_base::sync_with_stdio(false);
	while(cin >> n >> m)
	{
		for(int i = 0; i <= n; i++)
			graph[i].clear();
		double lo = 0.0;
		double hi = 1440.0;
		for(int k = 0; k < m; k++)
		{
			int i,j,a,b;
			cin >> i >> j >> a >> b;
			graph[i].push_back(make_pair(j,make_pair(a,b)));
			graph[j].push_back(make_pair(i,make_pair(a,b)));
		}
		for(int i = 0; i < 100; i++)
		{
			double mid1 = (2.0*lo+hi)/3.0;
			double mid2 = (2.0*hi+lo)/3.0;
			if(dijkstra(mid1) > dijkstra(mid2))
			{
				hi = mid2;		
			}
			else
				lo = mid1;
		}
		cout << fixed << setprecision(5) << dijkstra(lo) << "\n"; 
	}
}
