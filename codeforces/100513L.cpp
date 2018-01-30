#include <bits/stdc++.h>
#define LL long long
#define INF (1LL << 60)
using namespace std;
#define cl(a) memset(a,0,sizeof(a))
template<class T> inline
void read(T& x) {
	int f = 1; x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')   {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}
 

 
const int N = 201000 + 5;
// const int N = 100 + 5;
 
int n, m, dfn;
int idom[N], sdom[N], DFN[N], idx[N];
long long sz[N];
int f[N], fa[N], val[N];
vector<int> V[N], P[N], B[N];
vector<int>graph[N];
 
void dfs(int x) {
	DFN[x] = sdom[x] = ++dfn; idx[dfn] = x;
	for (int i = 0; i < V[x].size(); i++) {
		int y = V[x][i];
		if (!sdom[y]) fa[y] = x, dfs(y);
	}
}
 
int find(int x) {
	if (f[x] == x) return x;
	int p = find(f[x]);
	val[x] = sdom[val[f[x]]] < sdom[val[x]] ? val[f[x]] : val[x];
	return f[x] = p;
}
 
int eval(int x) {find(x); return val[x];}
 
void getidom() {
	for (int i = 1; i <= n; i++) f[i] = val[i] = i;
	for (int T = dfn; T > 1; T--) {
		int x = idx[T], u;
		for (int i = 0; i < P[x].size(); i++) {
			int y = P[x][i];
			if (sdom[y]) sdom[x] = min(sdom[x], sdom[eval(y)]);
		}
		B[idx[sdom[x]]].push_back(x);
		u = f[x] = fa[x]; // link x --> fa[x]
		for (int i = 0; i < B[u].size(); i++) {
			int w = B[u][i];
			if (sdom[eval(w)] == sdom[u]) idom[w] = sdom[w]; // u = idx[sdom[w]]
			else idom[w] = DFN[eval(w)];
		}
		B[u].clear();
	}
	for (int T = 1; T <= dfn; T++) {
		int x = idx[T];
		if (idom[x] != sdom[x]) idom[x] = idom[idx[idom[x]]];
		else idom[x] = idx[sdom[x]];
	}
}
int in[N];
int out[N];
int cnt = 0;
void dfs1(int u , int pai)
{
	in[u] = cnt;
	for(int i = 0 ; i < graph[u].size(); i++)
	{
		int v = graph[u][i];
		if(v == pai)
			continue;
		dfs1(v,u);
		cnt++;
	}
	out[u] = cnt;
}
vector<pair<int,int> >ed;	
vector<int>ans;
int main()
{
	while(scanf("%d %d",&n,&m) != EOF)
	{
		dfn = 0;
		for(int i = 1; i <= n ; i++)
		{
			V[i].clear();
			P[i].clear();
			B[i].clear();
		}
			cl(idom);
			cl(sdom);
			cl(DFN);
			cl(idx);
			cl(fa);
			cl(f);
			cl(val);
		ans.clear();
		ed.clear();
		for (int i = 1, x, y; i <= m; i++)
		{
			read(x);
			read(y);
			ed.push_back({x,y});
			V[x].push_back(y);
			P[y].push_back(x);
		}
		dfs(1);
		getidom();
		for(int i = 2; i <= n; i++)
		{
			graph[idx[i]].push_back(idom[idx[i]]);
			graph[idom[idx[i]]].push_back(idx[i]);
		}
		cnt = 0;
		dfs1(1,1);
		for(int i = 0 ; i < m; i++)
		{
			int u = idx[ed[i].first];
			int v = idx[ed[i].second];
			if(u == 0 || v == 0)
				continue;
			if( (in[u] <= in[v] || out[u] >= out[v]))
				ans.push_back(i+1);
		}
		printf("%d\n",(int)ans.size());
		for(int i = 0 ; i < ans.size(); i++)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
} 