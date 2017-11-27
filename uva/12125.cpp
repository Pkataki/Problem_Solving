#include<bits/stdc++.h>
using namespace std;

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long
const int INF = 0x3f3f3f3f;
const int MAXN = 505;
const int MAXE = 100500;

int src, snk, nNode, nEdge;
int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
int flow[MAXE], cap[MAXE], nxt[MAXE], to[MAXE],rest[MAXE];

inline void init(int _src, int _snk, int _n) {
	src = _src, snk = _snk, nNode = _n, nEdge = 0;
	SET(fin);
}

inline void add(int u, int v, int _cap) {
	to[nEdge] = v, cap[nEdge] = _cap, rest[nEdge] = _cap ,flow[nEdge] = 0;
	nxt[nEdge] = fin[u], fin[u] = nEdge++;
	
	to[nEdge] = u, cap[nEdge] = 0, rest[nEdge] = 0, flow[nEdge] = 0;
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
			if(df > 0) {
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
		for(int i=0; i<=nNode; i++) pro[i] = fin[i];
		while(true) {
			df = dfs(src, INF);
			if(df) ret += df;
			else break;
		}
	}
	return ret;
}
void recover()
{
	for(int i = 0; i < nEdge; i++)
	{
		flow[i] = 0;
		cap[i] = rest[i];
	}				
}
int main()
{
	int test;
	int x[105];
	int y[105];
	int qt[105];
	int t[105];
	scanf("%d",&test);
	while(test--)
	{
		int n;
		double d;
		scanf("%d %lf",&n,&d);
		init(2*n+1, n ,2*n+10);
		
		int val = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d %d %d",&x[i],&y[i],&qt[i],&t[i]);
			add(src,i,qt[i]);
			add(i,n+i,t[i]);
			val += qt[i];
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(i != j && (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= d*d)
				{
					add(n+i,j,INF);
					add(n+j,i,INF);
				}
			}
		}
		vector<int>ans;
		for(int i = 0; i < n; i++)
		{
			snk = i;
			recover();
			if(dinitz() == val)
			{
				ans.push_back(i);
			}
		}
		if(ans.size())
		{
			for(int i = 0; i < ans.size(); i++)
			{
				if(i)
					printf(" ");
				printf("%d",ans[i]);
			}
			puts("");
		}
		else
		{
			puts("-1");
		}
	}
}
