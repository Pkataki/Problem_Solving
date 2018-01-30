#include<bits/stdc++.h>

using namespace std;

const int N = int(1e5)+10;
const int LOGN = 20;
const int INF = int(1e9);
set<int> g[N];
vector<int>small[N][20], v1[N];
int par[N],sub[N],level[N];
int d[N];
int n,m;

void join(vector<int>&v, vector<int> v1)
{
	for(int i = 0 ; i < v1.size(); i++)
		v.push_back(v1[i]);
	sort(v.begin(),v.end());
	int si = unique(v.begin(),v.end()) - v.begin();
	v.resize(min(si,10));
}
/*-----------------Decomposition Part--------------------------*/

int nn;
void dfs1(int u,int p)
{
	sub[u]=1;
	nn++;
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p)
		{
			dfs1(*it,u);
			sub[u]+=sub[*it];
		}
}
int dfs2(int u,int p)
{
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p && sub[*it]>nn/2)
			return dfs2(*it,u);
	return u;
}

void dfs3(int u, int p, vector<int>v, int dep)
{
	join(v,v1[u]);
	small[u][dep] = v;
	for(int a : g[u])
	{
		if(a == p)
			continue;
		dfs3(a,u,v,dep);
	}
}

void decompose(int root,int p, int dep)
{
	nn=0;
	dfs1(root,root);
	int centroid = dfs2(root,root);
	if(p==-1)p=centroid;
	par[centroid] = p;
	d[centroid] = dep;
	dfs3(centroid ,centroid, vector<int>() , dep);
	for(auto it=g[centroid].begin(); it != g[centroid].end(); it++)
	{
		g[*it].erase(centroid);
		decompose(*it,centroid, dep+1);
	}
	g[centroid].clear();
}
/*----------------- Handle the Queries -----------------*/

void query(int u, int v, int k)
{
    int x = u, y = v;
    while(x != y)
    {
        if (d[x] < d[y]) 
        	y = par[y];
        else 
        	x = par[x];
    }
    vector<int> ans;

    join(ans, small[u][d[x]]);
    join(ans, small[v][d[x]]);

    int cont = min(k, (int)ans.size());

    printf("%d ", cont);
    for (int i = 0; i < cont; i++) 
    	printf("%d ", ans[i]+1);
    printf("\n");
}
int main()
{
	int q;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		g[u-1].insert(v-1);
		g[v-1].insert(u-1);
	}
	for(int i = 0 ; i < m ; i++)
	{
		int a;
		scanf("%d",&a);
		a--;
		v1[a].push_back(i);
	}
	decompose(0,-1,0);
	
	while(q--)
	{
		int t,v,k;
		scanf("%d %d %d",&t,&v,&k); 
		t--, v--;
		query(t,v,k);
	}
	return 0;
}