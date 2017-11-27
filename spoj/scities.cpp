#include<bits/stdc++.h>
using namespace std;
#define MAXN 111   // Max # of vertexes
#define MAXM 5111  // Max # of edges

int N, M, source, sink;  // N - # of vertexes, M - # of edges, source and sink
#define int64 long long 
int64 f[MAXN][MAXN];  // f[u][v]  .. current flow on edge u -> v
int64 c[MAXN][MAXN];  // c[u][v]  .. capacity of edge u -> v

int64 dist[MAXN], aug[MAXN], parent[MAXN];
int u[MAXM], v[MAXM], w[MAXM];   // source, dest. and weight of edges

int64 augment(){  // Successive shortest path, bellman ford.. nodes from 0 to N-1
	int64 ww;
	for( int i = 0; i < N; i++ ) dist[i] = aug[i] = 2e15, parent[i] = -1;
	dist[source] = 0;
	bool need;
	do{
		need = false;
		for( int k = 0; k < M; k++ ){ 
			int i = u[k];
			int j = v[k];
			if( f[i][j] < c[i][j] ){
				if( f[i][j] < 0 ) ww = -w[k]; else ww = w[k];
				if( dist[j] > dist[i]+ww ){
					dist[j] = dist[i]+ww;
					aug[j] = min( aug[i], c[i][j]-f[i][j] );
					parent[j] = i;
					need = true;
				}
			}
			// Only need this when it's a undirected graph..
			i = v[k];
			j = u[k];
			if( f[i][j] < c[i][j] ){
				if( f[i][j] < 0 ) ww = -w[k]; else ww = w[k];
				if( dist[j] > dist[i]+ww ){
					dist[j] = dist[i]+ww;
					aug[j] = min( aug[i], c[i][j]-f[i][j] );
					parent[j] = i;
					need = true;
				}
			}
			// ...*/
		}
	} while( need );
	
	if( parent[sink] == -1 ) return 0;
	
	int v = sink;
	while( parent[v] != -1 ){
		f[parent[v]][v] += aug[sink];
		f[v][parent[v]] -= aug[sink];
		v = parent[v];
 	}
	return dist[sink]*aug[sink];
}

int64 minCostMaxFlow(){
	int64 cf, ans = 0;
	while( true ){
		cf = augment();
		if( cf == 0 ) break;
		ans += cf;
	}
	return ans;
}
main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int h,q;
		cin >> h >> q;
		N = h+q+2;
		int so,dest,cost;
		M = 0;
		while(cin >> so >> dest >> cost && (so && dest && cost))
		{
			
			u[M] = so;
			v[M] = dest+h;
			w[M] = -cost;
			c[so][dest+h] = c[dest+h][so] = ();
//			f[so][dest+h] =  1;
			M++;
		}
		source = 0;
		sink = h+q+1;
		for(int i = 0; i < h; i++)
		{
			u[M] = source;
			v[M] = i+1;
			w[M] = 0;
			c[source][i+1] = c[i+1][source] = 1;
//			f[source][i+1] = 1;
			M++;
		}
		for(int i = 1; i <= q; i++)
		{
			u[M] = h+i;
			v[M] = sink;
			w[M] = 0;
			f[h+i][sink] = f[sink][h+i] = 1;
//			f[h+i][sink] = 1;
			M++;
		}
		cout << minCostMaxFlow() << "\n";

	}
}
