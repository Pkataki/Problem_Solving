
#include<bits/stdc++.h>
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

	fill( best, best + 2 * V+ 2, oo );
	best[src] = 0;
	
     	queue< int > Q;
	for ( Q.push( src ); !Q.empty(); Q.pop() ) {
		int u = Q.front();
		for ( int e = head[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
		      if ( edges[e].cap && best[u] + edges[e].w < best[v] ) {
				Q.push( v );
				best[v] = best[u] + edges[e].w;
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


int main() {

	scanf( "%d", &T );
	while(T--) 
	{

		scanf( "%d %d", &V, &L);
		E = 0;
		memset( head, -1, sizeof( head ) );
		src = 2*V;
		snk = 2*V + 1;

		for(int i = 0 ; i < L; i++)
		{
			int u, v,co;
			scanf( "%d %d %d", &u, &v,&co );
			u--; v--;
			add_edge( u, v+V, co, 1);
		}
		
		for(int i = 0; i < V; i++)
		{
			add_edge(src,i,0,1);
			add_edge(i+V,snk,0,1);
		}
		sol = 0;
		while ( augment( src, snk ) );
		
		printf( "%d\n", sol );
	}

	return 0;
}
