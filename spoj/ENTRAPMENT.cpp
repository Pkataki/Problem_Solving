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
 

 
const int N = 101000 + 5;
// const int N = 100 + 5;
 
int n, m, dfn;
int idom[N], sdom[N], DFN[N], idx[N];
int f[N], fa[N], val[N];
std::vector<int> V[N], P[N], B[N];
 
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
 
int main()
{
	int test;
	read(test);
	while(test--)
	{
		read(n), read(m);
		for(int i = 1; i <= n ; i++)
		{
			P[i].clear();
			V[i].clear();
			B[i].clear();
		}
		dfn = 0;

			cl(idom);
			cl(sdom);
			cl(DFN);
			cl(idx);
			cl(fa);
			cl(f);
			cl(val);
		for (int i = 1, x, y; i <= m; i++) {
			read(x), read(y);
			P[x].push_back(y);
			V[y].push_back(x);
		}
		dfs(n);
		getidom();
		printf("%d\n",idom[1]);
	}
	return 0;
} 