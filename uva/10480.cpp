#include<bits/stdc++.h>
using namespace std;
int res[60][60];
vector<int>graph[55];
int flow,src,snk;
int parent[55];
bool visited[55];
set<int>ans;
void dfs(int u)
{
	visited[u] = 1;
	ans.insert(u);
	for(int i = 0; i < graph[u].size(); i++)
	{
		int v = graph[u][i];
		if(!visited[v] && res[u][v] > 0)
			dfs(v);
	}
}
void mincut()
{
	memset(visited,0,sizeof(visited));
	dfs(src);
	for(set<int>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		int at = *it;
//		cout << at << " ->> \n";
		for(int i = 0; i < graph[at].size(); i++)
		{
			int v = graph[at][i];
//			cout << v << " \n";
			if(visited[v])
				continue;
			printf("%d %d\n",at,v);		
		}
	}
	puts("");
}
void augment(int v, int minEdge) {
	if (v == src) {
		flow = minEdge;
		return;
	} else if (parent[v] != -1) {
		augment(parent[v], min(minEdge, res[parent[v]][v]));
		res[parent[v]][v] -= flow;
		res[v][parent[v]] += flow;
	}
}

int mflow;
void edmond_karp() {
	mflow = 0;
	while (1) {
		flow = 0;
		bitset<55> vis;
		vis.set(src);
		queue<int> q;
		q.push(src);
		memset(parent,-1,sizeof(parent));
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			if (u == snk)
				break;
			for (int i = 0; i < (int) graph[u].size(); i++) {
				int v = graph[u][i];
				if (res[u][v] > 0 && !vis.test(v)) {
					vis.set(v);
					q.push(v);
					parent[v] = u;
				}
			}
		}
		augment(snk, (1 << 30));
		if (flow == 0 || flow == (1 << 30) )
			break;
		mflow += flow;
	}
}
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m) && n || m)
	{
		ans.clear();
		memset(res,0,sizeof(res));
		for(int i = 0; i < 55; i++)
			graph[i].clear();
		
		for(int i = 0; i < m; i++)
		{
			int u,v,c;
			scanf("%d %d %d",&u, &v, &c);
			graph[u].push_back(v);	
			graph[v].push_back(u);	
			res[u][v] += c;
			res[v][u] += c;
		}
		src = 1;
		snk = 2;
		edmond_karp();
		mincut();
	}
}
