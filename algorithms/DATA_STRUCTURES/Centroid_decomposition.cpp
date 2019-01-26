#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5)+10;
const int LOGN = 20;
const int INF = int(1e9);
set<int> graph[N];
int par[N],sub[N],level[N],cor[N];
int ancestor[LOGN][N];
int n,m;

/*Using centroid Decomposition of a tree */


/*-----------------Decomposition Part--------------------------*/
int nn;
void dfs1(int u,int p)
{
	sub[u]=1;
	nn++;
	for(auto it = graph[u].begin();it != graph[u].end();it++)
	{
		if(*it != p)
		{
			dfs1(*it,u);
			sub[u]+=sub[*it];
		}
	}
}
int dfs2(int u,int p)
{
	for(auto it=graph[u].begin();it!=graph[u].end();it++)
		if(*it != p && sub[*it] > (nn/2))
			return dfs2(*it,u);
	return u;
}
void decompose(int root,int p)
{

	nn=0;
	dfs1(root,root);
	int centroid = dfs2(root,root);
	if(p == -1)
		p = centroid;
	par[centroid] = p;
	for(auto it = graph[centroid].begin();it!=graph[centroid].end();it++)
	{
		graph[*it].erase(centroid);
		decompose(*it,centroid);
	}
	graph[centroid].clear();
}
