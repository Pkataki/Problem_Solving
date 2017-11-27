#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >graph(405);
int n,m;
int _time;
int d[405];
int low[405];
int father[405];
bool vis[405];
bool ap[405];
void articulation_point(int u)
{
	d[u] = low[u] = _time++;
	int num_children = 0;
	vis[u] = true;
	for(int i = 0; i < graph[u].size(); i++)
	{
		int v = graph[u][i];
		if(!vis[v])
		{
			father[v] = u;
			num_children++;
			articulation_point(v);
			low[u] = min(low[u],low[v]);
			if(father[u] != -1 && low[v] >= d[u])
			{
				ap[u] = true;
			}
			else if(father[u] == -1 && num_children > 1)
			{
				ap[u] = true;
			}
		}
		else if(v != father[u])
		{
			low[u] = min(low[u],d[v]);
		}
	}
}
main()
{
	int test = 1;
	while(cin >> n >> m && (n || m))
	{
		_time = 0;
		memset(vis,false,sizeof(vis));		
		memset(low,0,sizeof(low));		
		memset(ap,false,sizeof(ap));		
		memset(father,-1,sizeof(father));		
		for(int i = 0; i < 405; i++)
			graph[i].clear();
		
		for(int k = 0; k < m; k++)
		{
			int a,b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		articulation_point(1);
		int ok = 0;
		cout << "Teste " << test << "\n";
		test++;
		for(int i = 1; i <= n; i++)
		{
			if(ap[i] && !ok)
			{
				ok = 1;
				cout << i;
			}
			else if(ap[i] && ok )
			{
				cout << " " << i;
			}
		}
		if(!ok)
		{
			cout << "nenhum";
		}
		cout << "\n\n";
	}
}
