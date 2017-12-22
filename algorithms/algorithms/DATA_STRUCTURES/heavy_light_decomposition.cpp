#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
vector< pair<int,int > > gr[MAXN];

int depth[MAXN], parent[MAXN], treesz[MAXN];
int chain[MAXN], chainpos[MAXN], chainleader[MAXN];

int N, cur_chain, pos;

int tree[4*MAXN];
int edge[MAXN];
void build(int node, int l, int r)
{
	if(l == r)
	{
		tree[node] = edge[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node] = max(tree[2*node+1],tree[2*node]);
}

void update(int node ,int l, int r, int x, int val)
{
	if( l > r )
		return;
	if(l == r)
	{
		tree[node] = val;
		return;
	}
	int mid = (l+r ) >> 1;
	if(x <= mid)
		update(2*node,l,mid,x,val);
	else
		update(2*node+1,mid+1,r,x,val);
	
	tree[node] = max(tree[2*node+1],tree[2*node]);
}

int query(int node ,int l, int r, int x, int y)
{
	if( l > r || l > y || r < x || x > y)
		return 0;
	
	if(x <= l && r <= y)
	{
		return tree[node];
	}
	int mid = (l+r) >> 1;

	return max( query(2*node, l , mid, x, y), query(2*node+1, mid+1, r , x , y));
}

void explore(int u) {
	int v;
	treesz[u] = 1;
	for (size_t i = 0, sz = gr[u].size(); i < sz; ++i) {
		v = gr[u][i].first;

        if (parent[ v ] == -1) {
			parent[ v ] = u;
			depth[ v ] = depth[ u ] + 1;
			explore(v);
			treesz[ u ] += treesz[ v ];
		}
	}
}

void decompose(int u, int custo, bool light = true ) {
	if (light) {
		++cur_chain;
		chainleader[ cur_chain ] = u;
	}
	
	chain[ u ] = cur_chain;
	chainpos[ u ] = pos++;
	edge[pos-1] = custo;
	int v, ind = -1, mx = -1, c;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		v = gr[u][i].first;

        if (parent[ v ] == u && (mx == -1 || treesz[mx] < treesz[v]))
			mx = v, ind = i, c = gr[u][i].second;
	}
	
	if (mx != -1) {
		decompose(mx, c, false);
	}
	
	for (size_t i = 0, sz = gr[u].size(); i < sz; ++i) {
		v = gr[u][i].first;
        if (parent[ v ] == u && v != mx) {
			decompose( v, gr[u][i].second );
		}
	}		
}

int lca(int u, int v) {
	while (chain[u] != chain[v]) 
	{
		if (depth[ chainleader[chain[u]] ] < depth[ chainleader[chain[v]] ])
			v = parent[ chainleader[ chain[v] ] ];
		else
			u = parent[ chainleader[ chain[u] ] ];
	}
	if (depth[u] < depth[v]) return u;
	return v;
}

int query_hld(int u, int v)
{
	int ans = 0;
	int uchain,vchain;
	vchain = chain[v];
	while(1)
	{
		uchain = chain[u];

		if(uchain == vchain)
		{
			if(v != u)
				ans = max(ans,query(1,0,pos-1,chainpos[v]+1,chainpos[u]));
			
			break;
		}
		else
		{
			ans = max(ans,query(1,0,pos-1, chainpos[chainleader[chain[u]]]+1,chainpos[u]));

			ans = max(ans,query(1,0,pos-1, chainpos[chainleader[chain[u]]] , chainpos[chainleader[chain[u]]]));
			
			u = parent[chainleader[chain[u]]];
		}
	}
	return ans;
}

int query_up(int u, int v)
{
	int LCA = lca(u,v);
	int ans = 0;
	ans = query_hld(u,LCA);
	ans = max(ans,query_hld(v,LCA));
	return ans;
}

vector< pair<int,int> > arestas;

int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	while(test--)
	{
		arestas.clear();
		memset(depth,0,sizeof(depth));
		memset(treesz,0,sizeof(treesz));
		cur_chain = -1;
		pos = 0;
		for(int i = 0 ; i < MAXN; i++)
		{
			gr[i].clear();
			parent[i] = -1;
			edge[i] = 0;
		}
		int n;
		cin >> n;
		for(int i = 1; i < n ; i++)
		{
			int a,b,c;
			cin >> a >> b >> c;
			arestas.push_back(make_pair(a,b));
			gr[a].push_back(make_pair(b,c));
			gr[b].push_back(make_pair(a,c));
		}
		parent[1] = 0;
		explore(1);
		decompose(1,0);
		build(1,0,pos-1);
		string s;
		while(cin >> s && s != "DONE")
		{
			int a,b;
			cin >> a >> b;
			if(s == "CHANGE")
			{
				int lo = arestas[a-1].first;
				int hi = arestas[a-1].second;
				
				if( chainpos[lo] < chainpos[hi] ){
					update(1,0,pos-1, chainpos[hi], b );
				}
				else{
					update(1,0,pos-1, chainpos[lo], b );
			
				}		
			}
			else
			{
				cout << query_up(a,b) << '\n';
			}
		}
	}
	return 0;
}
