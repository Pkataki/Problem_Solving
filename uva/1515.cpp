#include<bits/stdc++.h>
using namespace std;

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long

const int INF = 0x7fffffff;
const int MAXN = 40010;
int  MAXE = MAXV * 200 * 2;

int src, snk, nNode, nEdge;
int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
int flow[MAXE], cap[MAXE], next[MAXE], to[MAXE];

inline void init(int _src, int _snk, int _n) {
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    SET(fin);
}

inline void add(int u, int v, int c) {
    to[nEdge] = v;
    cap[nEdge] = c;
    flow[nEdge] = 0;
    next[nEdge] = fin[u];
    fin[u] = nEdge++;
    
    to[nEdge] = u;
    cap[nEdge] = c;
    flow[nEdge] = 0;
    next[nEdge] = fin[v];
    fin[v] = nEdge++;
}

bool bfs()
{
    int st, en, i, u, v;
    SET(dist);
    dist[src] = st = en = 0;
    Q[en++] = src;
    while(st < en)
    {
        u = Q[st++];
        for(i = fin[u]; i >= 0; i = next[i])
        {
            v = to[i];
            if(flow[i] < cap[i] && dist[v]==-1)
            {
                dist[v] = dist[u]+1;
                Q[en++] = v;
            }
        }
    }
    return dist[snk] != -1;
}

int dfs(int u, int fl) {
    if(u == snk)
    	return fl;
    for(int &e = pro[u], v, df; e >= 0; e = next[e])
    {
        v = to[e];
        if(flow[e] < cap[e] && dist[v] == dist[u]+1)
        {
            df = dfs(v, min(cap[e] - flow[e], fl));
            if(df > 0)
            {
                flow[e] += df;
                flow[e^1] -= df;
                return df;
            }
        }
    }
    return 0;
}

i64 dinic() {
    i64 ret = 0;
    int df;
    while(bfs()) {
        for(int i = 1; i <= nNode; i++)
        	pro[i] = fin[i];
        while(true) {
            df = dfs(src, INF);
            if(df) ret += (i64)df;
            else break;
        }
    }
    return ret;
}

int main() {
    int n,m;
    int test;
	scanf("%d",&test);
	char mat[60][60];
	int d,f,b;
	while(test--)
	{
		scanf("%d %d", &n, &m);

		scanf("%d %d %d", &d, &f,&b);
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				scanf("%c",&mat[i][j]);
				if((!i || !j || i == n-1 || j == m-1) && mat[i][j] == '.')
				{
					mat[i][j] = '#';
					ans += f;
				}
			}
		}


   
   /*nit(1, n, n);
    for(i=0; i<e; i++) {
        scanf("%d%d%d", &u, &v, &c);
        if(u!=v) add(u, v, c);
    }
    printf("%lld\n", dinic());
    */
	}
	return 0;
}

