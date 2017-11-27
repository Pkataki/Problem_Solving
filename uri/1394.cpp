#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long int64;
 
const int
	MAXN = 502,
	MAXE = 100000,
	oo = (int)1e9;
 
int T, V, L, E;
int src, snk, sol;
int cant[MAXN];
int best[MAXN];
int from[MAXN];
int head[MAXN];
struct edge {
	int u, v, w, cap, next;
} edges[MAXE];
 
void add_edge( int u, int v, int w, int cap ) {
	edges[E++] = (edge){ u, v, +w, cap, head[u] };
	head[u] = E - 1;
	edges[E++] = (edge){ v, u, -w, 0, head[v] };
	head[v] = E - 1;
}
 
bool augment( int src, int snk ) {
 
	fill( best, best + V + 2, oo );
	best[src] = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int> >,
                                greater<pair<int, int> > > Q;
	Q.push(make_pair(0,src));
	while(!Q.empty())
	{
		int u = Q.top().second;
		Q.pop();
		for ( int e = head[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
		      if ( edges[e].cap && best[u] + edges[e].w < best[v] ) {
				best[v] = best[u] + edges[e].w;
				
				Q.push(make_pair(best[v],v));
				
				from[v] = e;
			}
		}
	}
	
	if ( best[snk] == oo )
	      return false;
	      
	sol += best[snk];
	for ( int x = snk; x != src; x = edges[ from[x] ].u ) {
		edges[ from[x] ].cap--;
		edges[ from[x]^1 ].cap++;
	}
	      
	return true;
}
int v[100];
int main()
{
	int n,m,g;
	while(scanf("%d %d %d",&n,&m,&g) == 3 && ((n + m + g) != 0))
	{
		E = 0;
		V = n;
		memset(v,0,sizeof(v));
		memset( head, -1, sizeof( head ) );
		for(int i = 0 ; i < g; i++)
		{
			int a,c;
			char b;
			scanf("%d %c %d",&a,&b,&c);
			if(b == '=')
			{
				add_edge( a, c, 1, 1 );
				add_edge( c, a, 1, 1 );
				v[a]++;
				v[c]++;
			}
			else if(b == '<')
			{
				add_edge( a, c, 2, 1 );
				v[a]++;
			}
			else
			{
				add_edge( c, a, 2, 1 );
				v[c]++
			}
		}
		src = V ;
		snk = V+1;
		for(int i = 0; i < V; i++)
		{
			add_edge( src, i, 0, v[i] );
			add_edge( i, snk, 0, INT_MAX);
		}
		sol = 0;
		while ( augment( src, snk ) );
		for(int i = 0 ; i < )
	}
	return 0;
}
 
