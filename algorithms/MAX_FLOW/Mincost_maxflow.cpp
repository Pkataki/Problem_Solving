#include<bits/stdc++.h>
using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))

const long long INF = (1LL << 60);

const int maxn = 1005;
const int maxe = 2000007;

struct Edge
{
    int u, v, next;
    long long cost, cap;
    
    Edge(){}

    Edge(int u, int v, int next, long long cost, long long cap) : u(u), v(v),
    next(next), cost(cost), cap(cap){}
} e[maxe]; 

int edgenum, first[maxn], par[maxn];
int rec[maxn], vis[maxn];
long long  dist[maxn];

void addEdge( int u, int v, long long c, long long f)
{
	e[edgenum] = Edge(u,v,first[u],c,f);
    first[u] = edgenum;
    edgenum++;

    e[edgenum] = Edge(v,u,first[v],-c,0);
    first[v] = edgenum;
    edgenum++;
}


void desopo(int node, int source)
{
    deque <int> q;

    for (int i = 0 ; i <= node; i++)
		dist[i] = INF;
    
    SET(par);
	CLR(vis);
    dist[source] = 0;
    q.push_front(source);
    vis[source] = 1;
    while (q.size())
    {
        int u = q.front();
        vis[u] = 2;
        q.pop_front();
        for ( int k = first[u]; k != - 1 ; k = e[k].next)
        {
            int v = e[k].v;
			if (e[k].cap > 0 && (dist[u] + e[k].cost) < dist[v])
            {
            
            	par[v] = u;
                dist[v] = dist[u] + e[k].cost;
                rec[v] = k;
				if(vis[v] == 0)
                {
                    vis[v] = 1;
                    q.push_back(v);
                }
                else if(vis[v] == 2)
                {
                    vis[v] = 1;
                    q.push_front(v);
                }
            }
        }
    }
    return;
}

pair<long long, long long> MCMF(int source, int sink, int node)
{
    long long F = 0, mn;
    long long C = 0;
    while ( 1 )
    {
        desopo(node, source);
        if (dist[sink] == INF)  
            break ;
        mn = INF;
        for ( int k = sink; k != source ; k = par[k])
        {
            int r = rec[k];
            mn = min(mn, max(0LL , e[r].cap));
        }
        for ( int k = sink; k != source ; k = par[k])
        {
            int r = rec[k];
            e[r].cap -= mn;
            e[r^1].cap += mn;
            e[r^1].cost = -e[r].cost;
        }
        F += mn; 
        C += mn * dist[sink];
    }
    return make_pair(F,C);
}


void init() // dont forget this
{
	SET(first);
	edgenum = 0;
}

