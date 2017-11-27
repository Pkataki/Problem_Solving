#include<bits/stdc++.h>
using namespace std;
typedef struct no
{
       int h, e, r;
}no;

no tree[530005];
int lazy[530005];

void build (int node, int lo, int hi)
{
	lazy[node] = 0;
	if ( lo == hi )
	{
		tree[node].h = 1;
		tree[node].e = 0;
		tree[node].r = 0;
 	}
	else
	{
		int mid = (lo + hi) >> 1;
		build(node*2, lo, mid);
		build(node*2+1, mid+1, hi);
		tree[node].h = tree[2*node].h + tree[2*node+1].h;
		tree[node].e = tree[2*node].e + tree[2*node+1].e;
		tree[node].r = tree[2*node].r + tree[2*node+1].r;
	}
}

no get (int node)
{
	if ( !lazy[node] ) 
		return tree[node];
	for (int i = 0; i < lazy[node]; i++ )
	{
        int x = tree[node].h;
		tree[node].h = tree[node].r;
		tree[node].r = tree[node].e;
		tree[node].e = x;
	}
	lazy[2*node] = (lazy[2*node] + lazy[node]) % 3;
	lazy[2*node+1] = (lazy[2*node+1] + lazy[node]) % 3;
	lazy[node] = 0;
	return tree[node];
}

no query (int node, int lo, int hi, int l, int r)
{
    no zero;
    zero.h = 0; zero.e = 0; zero.r = 0;
	if ( l > hi || r < lo )
		return zero;
	if ( lo >= l && hi <= r )
		return get(node);	
	else
	{
		int mid = (lo + hi) >> 1;
		get(node);
		no a = query(2*node, lo, mid, l, r);
		no b = query(2*node+1, mid+1, hi, l, r);
		a.h += b.h; a.e += b.e; a.r += b.r;
		return a;
	}
}

void update (int node, int lo, int hi, int l, int r){
	if ( l > hi || r < lo )
		return;
	if ( lo >= l && hi <= r )
	{
		lazy[node] = (lazy[node] + 1) % 3;
        return;
	}
	else
	{
		int mid = (lo + hi) >> 1;
		update(2*node, lo, mid, l, r);
		update(2*node+1, mid+1, hi, l, r);
		no a = get(2*node);
		no b = get(2*node+1);
		a.h += b.h; a.e += b.e; a.r += b.r;
		tree[node] = a;
	}
}

main()
{
	int n, m, a, b;
	char c;
	while ( scanf("%d %d", &n, &m) != EOF )
	{
		build(1, 0, n-1);
		while ( m-- )
		{
			scanf(" %c %d %d", &c, &a, &b);
			if ( c == 'C' )
			{
				no resp = query(1,0,n-1, a-1, b-1);
				printf("%d %d %d\n", resp.h, resp.e, resp.r);
			}
			else 
				update (1, 0, n-1, a-1, b-1);
		}
		printf("\n");
	}
}
