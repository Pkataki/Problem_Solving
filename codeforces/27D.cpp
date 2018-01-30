#include<bits/stdc++.h>
using namespace std;
const int maxn = 500;
vector<int>graph[maxn],rgraph[maxn];
int comp[maxn];
vector<int>order;
bool used[maxn];
int n,m;
void dfs1(int u)
{
	used[u] = 1;
	for(int i = 0 ; i <graph[u].size() ; i++)
	{
		int v = graph[u][i];
		if(used[v] == 0)
			dfs1(v);
	}
	order.push_back(u);
}
void dfs2(int u, int cl)
{
	comp[u] = cl;
	for(int i = 0; i < rgraph[u].size() ; i++)
	{
		int v = rgraph[u][i];
		if(comp[v] == 0)
			dfs2(v,cl);
	}
}
pair<int,int>v[maxn];
bool intersect(int i , int j)
{
	pair<int,int>pi = v[i];
	pair<int,int>pj = v[j];
	if(pi > pj)
		swap(pi,pj);
	if(pj.first > pi.first && pj.first < pi.second && pj.second > pi.second)
		return true;
	return false;
}
bool solve()
{
	for(int i = 0 ; i < n ; i++)
	{
		if(used[i] == 0)
			dfs1(i);
	}
	for(int i= 0, j = 0; i < n ; i++)
	{
		int v = order[n-i-1];
		if(!comp[v])
			dfs2(v,++j);
	}
	for(int i = 0 ; i < n ; i++)
	{
		if(comp[i] == comp[i^1])
			return false;
	}
	return true;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 0 ; i < m ; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a > b)
			swap(a,b);
		v[i] = {a,b};
	}
	n = 2*m;
	for(int i = 0; i < m; i++)
	{
		for(int j = i+1; j < m ; j++)
		{
			if(!intersect(i,j))
				continue;
			graph[2*i].push_back(2*j+1);
			rgraph[2*j+1].push_back(2*i);
			
			graph[2*j].push_back(2*i+1);
			rgraph[2*i+1].push_back(2*j);
			
			rgraph[2*i].push_back(2*j+1);
			graph[2*j+1].push_back(2*i);
			
			rgraph[2*j].push_back(2*i+1);
			graph[2*i+1].push_back(2*j);
			
		}	
	}
	if(solve())
	{
		for(int i = 0 ; i < n ; i += 2)
		{
			printf("%c", comp[i] > comp[i ^ 1] ? 'i' : 'o');
		}
		puts("");
	}
	else
	{
		puts("Impossible");
	}
	return 0;
}
