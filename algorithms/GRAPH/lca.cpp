#include <bits/stdc++.h>
using namespace std ;
int nivel[ 100005 ], pai[100005] ;
int ancestral[ 100005 ][ 18 ] ;
int dis[100005];
vector<pair<int,int> > graph[100005];
void dfs( int u ){
	for( int i = 0 ; i < graph[u].size() ; i++ )
	{
		int v = graph[u][i].first;
		if( !nivel[ v ] )
		{
			nivel[ v ]  = nivel[u] + 1 ;
			dis[ v ] = dis[u] + graph[u][i].second;
			pai[ v ] = u ;
			dfs( v ) ;
		}
	}
}

int LCA(int a, int b){
	if(nivel[a] < nivel[b])
		swap( a, b ) ;
	for(int i = 17 ; i >= 0 ; i--)
		if( nivel[a] - (1 << i) >= nivel[b] )
			a = ancestral[a][i] ;
	if( a == b )
		return b ;
	for ( int i = 17 ; i >= 0 ; i-- ){
		if( ancestral[a][i] != -1 && ancestral[a][i] != ancestral[b][i] )
			a = ancestral[a][i], b = ancestral[b][i] ;
	}
	return ancestral[a][0] ;
}

int getkth(int p, int q, int k){
	int lca = LCA(p, q), d;
	if (lca == p){
		d = nivel[q] - nivel[p] + 1;
		swap(p, q);//we want p to be at higher nivel.....so swap p and q if p is at lower nivel i.e. it is the lca
		k = d - k + 1;//decide 'k' accordingly i.e. k will now become total distance minus k as we have now change our p(which was originally q)
	}
	else if (q == lca);//do nothing if q is lca
	//case when neither p and q are lca
	else{
		d = nivel[p] + nivel[q] - 2 * nivel[lca] + 1;
		/*
		d denotes the total dist between the nodes p and q. it will be = dist(p,lca) + dist(lca,q) - 1
		= (nivel[p] - nivel[lca] + 1) + (nivel[q] - nivel[lca] + 1) - 1
		= nivel[p] + nivel[q] - 2 * nivel[lca] + 1
		*/
		if (k > nivel[p] - nivel[lca] + 1){//case when 'k' will be between lca and q i.e. dist b/w lca and 'p' is less than k
			k = d - k + 1;//change 'k' accordingly
			swap(p, q);//swap p and q  as we want to calculate the dist from 'p' only.
		}
	}
	//Now we have set starting node as 'p' and changed k accordingly such that the kth node between 'p'
	//and 'q' will always lie between 'p' and lca(p,q) at a dist 'k' from p
	//Also dist(p,lca) > k
	//cout << "p : " << p << "  q : " << q << "   k : " << k << "   lca : " << lca << endl;
	k--;//decrement k as k = 1 will indicate p itself.
	for (int i = 17; i >= 0; i--){
		if ((1 << i) <= k){//if k is greater than or equal to 2^i than we can move up by that much nodes
			p = ancestral[p][i];//p will become 2^i th ancestor of p
			k -= (1 << i);//we will move 2^i nodes up and k will be decreased by that amount
		}
	}
	return p;
}

int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		for(int i = 0; i < 100005; i++)
			graph[i].clear();
		memset(dis,0,sizeof(dis));
		memset(nivel,0,sizeof(nivel));
		memset(pai,0,sizeof(pai));
		int n ;
		cin >> n ;
		memset( ancestral, -1, sizeof( ancestral ) ) ;
		
		for(int i = 1 ; i < n ; i++)
		{
			int u,v,w;
			cin >> u >> v >> w;
			graph[u].push_back(make_pair(v,w));
			graph[v].push_back(make_pair(u,w));
		}
		
		nivel[1] = 1 ;
		pai[1] = 0 ;
		dfs( 1 )     ;
		for (int i = 1 ; i <= n ; ++i)
			ancestral[i][0] = pai[i] ;

		for (int j = 1 ; j < 17 ; j++)
			for (int i = 1 ; i <= n ; ++i)
				if( ancestral[i][j-1] != -1 )
					ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1] ;
		
		string s;
		int a,b,k;
		while(cin >> s && s != "DONE")
		{
			if(s == "DIST")
			{
				cin >> a >> b;
				cout << dis[a] + dis[b] - ( 2 * dis[LCA(a,b)]) << '\n';
			}
			else
			{
				cin >> a >> b >> k;
				cout << getkth(a,b,k) << '\n';
				
			}
		}
	}
	return 0;
}
