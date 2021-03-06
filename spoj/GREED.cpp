#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const int MAXN = 505;
const int MAXE = 100000;

int src, snk, nNode, nEdge;
int fin[MAXN], pre[MAXN], dist[MAXN], cont[MAXN];
int cap[MAXE], cost[MAXE], nxt[MAXE], to[MAXE], from[MAXE];
inline void init(int _src, int _snk, int nodes) {
    memset(fin,-1,sizeof(fin));
    memset(from,0,sizeof(from));
    memset(to,0,sizeof(to));
    memset(nxt,0,sizeof(nxt));
    memset(cost,0,sizeof(cost));
    memset(cap,0,sizeof(cap));
    nNode = nodes, nEdge = 0;
    src = _src, snk = _snk;
}
 
inline void addEdge(int u, int v, int _cap, int _cost) {
    from[nEdge] = u, to[nEdge] = v, cap[nEdge] = _cap, cost[nEdge] = _cost;
    nxt[nEdge] = fin[u], fin[u] = nEdge++;
    from[nEdge] = v, to[nEdge] = u, cap[nEdge] = 0, cost[nEdge] = -(_cost);
    nxt[nEdge] = fin[v], fin[v] = nEdge++;
}
 
bool bellman() {
    int iter, u, v, i;
    bool flag = true;
    memset(dist, 0x3f3f3f,sizeof(dist));
    memset(pre,-1,sizeof(pre));
    dist[src] = 0;
    for(iter = 1; iter < nNode && flag; iter++) {
        flag = false;
        for(u = 0; u < nNode; u++) {
            for(i = fin[u]; i >= 0; i = nxt[i]) {
                v = to[i];
                if(cap[i] && dist[v] > dist[u] + cost[i]) {
                    dist[v] = dist[u] + cost[i];
                    pre[v] = i;
                    flag = true;
                }
            }
        }
    }
    return (dist[snk] < INF);
}
 
int mcmf(int &fcost) {
    int netflow, bot, u;
    netflow = fcost = 0;
    while(bellman()) {
        bot = INF;
        
		for(u = pre[snk]; u >= 0; u = pre[from[u]]) 
			bot = min(bot, cap[u]);
        
		for(u = pre[snk]; u >= 0; u = pre[from[u]])
		{
            cap[u] -= bot;
            cap[u^1] += bot;
            fcost += bot * cost[u];
        }
        netflow += bot;
    }
    return netflow;
}

int main() {
	int test;
	cin >> test;
	while(test--)
	{
		int n1;
		cin >> n1;
		init(0, n1+1, n1+2);
		for(int i = 0 ; i < n1; i++)
		{
			int a;
			cin >> a;
			cont[a]++;
		}
		for(int i = 1; i <= n1; i++) 
		{
			if(cont[i])
				addEdge(0, i, cont[i], 0);
			
			addEdge(i, n1+1, 1,0);
		}
		int e;
		cin >> e;
		while(e--)
		{
			int a,b;
			cin >>a >> b;
			addEdge(a,b, INF, 1);
			addEdge(b,a, INF, 1);
		}
		int ans = 0;	
		mcmf(ans);
		cout << ans << "\n";
	}
	return 0;
}

