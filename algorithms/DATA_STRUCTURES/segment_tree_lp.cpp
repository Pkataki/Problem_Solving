#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
long long tree[4*MAXN][3];
long long lazy[4*MAXN];
void build(int node, int l, int r)
{
	if(l > r)
		return;
	if(l == r)
	{
		tree[node][0] = 1LL;
		tree[node][1] = 0LL;
		tree[node][2] = 0LL;
		return;
	}
	int mid = (l+r) >> 1;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	tree[node][0] = tree[2*node][0] + tree[2*node+1][0];
	tree[node][1] = tree[node][2]  = 0;
}
void rotate( int node ) 
{
	int temp = tree[node][0];
	tree[node][0] = tree[node][2];
	tree[node][2] = tree[node][1];
	tree[node][1] = temp;
}
void push(int node, int l, int r)
{
	if(lazy[node] == 0)
		return;
 
	if(l != r)
	{
		lazy[2*node+1] = (lazy[node] + lazy[2*node+1])%3;
		lazy[2*node] = (lazy[node] + lazy[2*node])%3;
	}
	for(int i = 0 ; i < lazy[node] ; i++)
	{
		rotate(node);
	}
 
	lazy[node] = 0;
}
int query(int node, int l , int r, int x, int y)
{
	if(l > r || l > y || r < x)
		return 0;
	push(node,l,r);
	if(x <= l && r <= y)
	{
		return tree[node][0];
	}
	int mid = (l+r) >> 1;
	push(2*node,l,mid);
	push(2*node+1,mid+1,r);
	return query(2*node,l,mid,x,y) + query(2*node+1,mid+1,r,x,y);
}
void update(int node, int l ,int r, int x, int y)
{	
	if(l > r || l > y || r < x)
		return ;
	push(node,l,r);
	if(x <= l && r <= y)
	{
		lazy[node]++;
		push(node,l,r);
		return;
	}
	int mid = (l+r) >> 1;
	push(2*node,l,mid);
	push(2*node+1,mid+1,r);
	update(2*node,l,mid,x,y);
	update(2*node+1,mid+1,r,x,y);
	for(int i = 0 ; i < 3 ; i++)
	{
		tree[node][i] = tree[2*node][i] + tree[2*node+1][i];
	}
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	build(1,0,n-1);
	int x,y,op;
	for(int i = 0; i < q ; i++)
	{
		scanf("%d %d %d",&op,&x,&y);
		if(op == 1)
			cout << query(1,0,n-1,x,y) << '\n';
		else	
			update(1,0,n-1,x,y);
	}
}
 