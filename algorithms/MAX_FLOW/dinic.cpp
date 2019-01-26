#include<bits/stdc++.h>
using namespace std;
const int maxn = 100105;
struct edge
{
	int u,v,cap,flow;
};
vector<edge>e;

vector<int>graph[maxn];

int dist[maxn];
int ptr[maxn];


void add_edge(int u , int v, int cap)
{
	edge e1 = {u,v,cap,0};
	edge e2 = {v,u,0,0};

	graph[u].push_back(e.size());
	e.push_back(e1);
	
	graph[v].push_back(e.size());
	e.push_back(e2);
}


bool bfs(int s, int t)
{
	memset(dist,-1, sizeof(dist));
	queue<int>q;
	q.push(s);
	dist[s] = 0;
	while(q.size() && dist[t] == -1)
	{
		int u = q.front();
		q.pop();

		for(int i = 0; i < graph[u].size(); i++)
		{
			int id = graph[u][i];
			int v = e[id].v;

			if(dist[v] == -1 && e[id].cap > e[id].flow)
			{
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}

	return dist[t] != -1;
}

int dfs(int u , int flow, int t)
{
	if(!flow)
		return 0;
	if(u == t)
		return flow;
	for(; ptr[u] < graph[u].size(); ptr[u]++)
	{
		int id = graph[u][ptr[u]];
		int v = e[id].v;

		if(dist[v] != dist[u] + 1)
			continue;
		
		int pushed = dfs(v, min(flow, e[id].cap - e[id].flow), t);
		
		if(pushed)
		{
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}

	}
	return 0;
}


int dinic(int s, int t)
{
	int ans = 0;
	while(bfs(s,t))
	{
		memset(ptr,0,sizeof(ptr));
		while(int pushed = dfs(s, (1 << 29), t) )
			ans += pushed;
	}
	return ans;
}