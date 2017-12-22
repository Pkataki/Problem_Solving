#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5)+10;
const int LOGN = 20;
const int INF = int(1e9);
set<int> graph[N];
int par[N],sub[N],level[N],cor[N];
int ancestor[LOGN][N];
int n,m;

template<typename T>
bool read( T &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar_unlocked(); 
    if( c == EOF) { n = -1; return false; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar_unlocked(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true; 
} 
 
template<typename T>
inline void writeInt(T n){ 
    register int idx = 20; 
    if( n < 0 ) putchar_unlocked('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 
/*Using centroid Decomposition of a tree */

/*----------- Pre-Processing ------------*/
/*------------Processing LCA-------------*/
void dfs0(int u)
{
	for(auto it = graph[u].begin(); it!=graph[u].end(); it++)
		if(*it != ancestor[0][u])
		{
			ancestor[0][*it]=u;
			level[*it]=level[u]+1;
			dfs0(*it);
		}
}
void preprocess()
{
	level[0]=0;

	ancestor[0][0]=0;
	
	dfs0(0);
	
	for(int i = 1;i < LOGN; i++)
		for(int j = 0;j < n; j++)
			ancestor[i][j] = ancestor[i-1][ancestor[i-1][j]];
}
int lca(int a,int b)
{
	if(level[a] > level[b])
			swap(a,b);

	int d = level[b] - level[a];
	for(int i = 0;i < LOGN; i++)
		if(d & (1<<i))
			b = ancestor[i][b];
	
	if(a == b)
		return a;
	
	for(int i = LOGN-1; i >= 0; i--)
	{
		if(ancestor[i][a] != ancestor[i][b])
		{
			a = ancestor[i][a];
			b = ancestor[i][b];
		}
	}
	return ancestor[0][a];
}
int dis(int u,int v)
{
	return level[u] + level[v] - 2*level[lca(u,v)];
}
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
/*----------------- Handle the Queries -----------------*/
map <int,int> ans[N];
int cont;
void update(int u)
{
	int x = u;
	if(cor[u] == 0)
		cont--;
	else
		cont++;
	while(1)
	{
		int d = dis(x,u);
		if(cor[u])
			ans[x][d]++;
		else
		{
			ans[x][d]--;
		
			if(ans[x][d] == 0)
				ans[u].erase(d);
		}
		if(x == par[x])
			break;
		x = par[x];
	}
}
int get(int u)
{
	if(ans[u].empty())
		return INF;
	map<int,int>::iterator it = ans[u].begin();
	return it->first;
}
int query(int u)
{
	int x = u;
	int ret = INF;
	while(1)
	{
		ret = min(ret, dis(u,x) + get(x));
		if(x == par[x])
			break;
		x = par[x];
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(0);
	read(n);
	for(int i = 0; i < n-1; i++)
	{
		int u,v;
		read(u);
		read(v);
		u--;
		v--;
		graph[u].insert(v);
		graph[v].insert(u);
	}
	preprocess();
	decompose(0,-1);
	for(int i = 0; i < n; i++)
	{
		cor[i] = 0;
	}
	read(m);
	while(m--)
	{
		int t,v;
		read(t);
		read(v);
		v--;
		if(t == 0)
		{
			cor[v] = 1 - cor[v];
			update(v);
		}
		else
		{
			
			int ans = query(v);
			if(cont && ans < INF)
			{
				writeInt(ans);
				putchar_unlocked('\n');
			}
			else
				puts("-1");
		}
	}
	return 0;
}
