#include<bits/stdc++.h>
using namespace std;

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long
const int INF = 0x3f3f3f3f;
const int MAXN = 405;
const int MAXE = 40500;

int src, snk, nNode, nEdge;
int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
int flow[MAXE], cap[MAXE], nxt[MAXE], to[MAXE];

inline void init(int _src, int _snk, int _n) {
	src = _src, snk = _snk, nNode = _n, nEdge = 0;
	SET(fin);
}

inline void add(int u, int v, int _cap) {
	to[nEdge] = v, cap[nEdge] = _cap, flow[nEdge] = 0;
	nxt[nEdge] = fin[u], fin[u] = nEdge++;
	to[nEdge] = u, cap[nEdge] = 0, flow[nEdge] = 0;
	nxt[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bfs() {
	int st, en, i, u, v;
	SET(dist);
	dist[src] = st = en = 0;
	Q[en++] = src;
	while(st < en) {
		u = Q[st++];
		for(i=fin[u]; i>=0; i=nxt[i]) {
			v = to[i];
			if(flow[i] < cap[i] && dist[v]==-1) {
				dist[v] = dist[u]+1;
				Q[en++] = v;
			}
		}
	}
	return dist[snk]!=-1;
}

int dfs(int u, int fl) {
	if(u==snk) return fl;
	for(int &e=pro[u], v, df; e>=0; e=nxt[e]) {
		v = to[e];
		if(flow[e] < cap[e] && dist[v]==dist[u]+1) {
			df = dfs(v, min(cap[e]-flow[e], fl));
			if(df>0) {
				flow[e] += df;
				flow[e^1] -= df;
				return df;
			}
		}
	}
	return 0;
}

int dinitz() {
	int ret = 0, df;
	while(bfs()) {
		for(int i=1; i<=nNode; i++) pro[i] = fin[i];
		while(true) {
			df = dfs(src, INF);
			if(df) ret += df;
			else break;
		}
	}
	return ret;
}

int main() {
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n;
		scanf("%d", &n);
   	 	init(1, n, n);
   	 	for(int v = 1; v < n; v++)
		{
			int e;
			scanf("%d",&e);
			for(int j = 0; j < e; j++)
			{
				int u;	
       			scanf("%d", &u);
        		add(v, u,(v == 1 || u == n) ? 1 : INF);
    		}
		}
   		printf("%d\n", dinitz());
    }
	return 0;
}

