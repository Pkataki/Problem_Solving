#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int v[MAXN];
int tree[4*MAXN][105];
bool lazy[4*MAXN];
void build(int node, int l , int r)
{
	if(l > r)
		return;
	lazy[node] = 0;
	for(int i = 1; i <= 100; i++)
	{
		tree[node][i] = i;
	}
	if(l == r)
		return;
	int mid = (l + r) >> 1;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
}
void push(int x){
	if(lazy[x] == 0)
		return;

	for(int i = 1; i <= 100; i++){
		tree[2 * x][i] = tree[x][tree[2 * x][i]];
		tree[2 * x + 1][i] = tree[x][tree[2 * x + 1][i]];
	}

	lazy[2 * x] = 1;
	lazy[2 * x + 1] = 1;

	for(int i = 1; i <= 100; i++)
		tree[x][i] = i;

	lazy[x] = 0;
}

void update(int node, int l, int r, int lo, int hi, int x, int y)
{
	if(l > r || lo > r || hi < l)
		return;
	if(lo <= l && r <= hi)
	{
		lazy[node] = 1;
		for(int i = 1; i <= 100; i++)
		{
			if(tree[node][i] == x)
			{
				tree[node][i] = y;
			}
		}
		//push(node);
		return;
	}
	push(node);
	int mid = (l + r) >> 1;
	update(2*node, l, mid, lo, hi,x,y);
	update(2*node+1, mid+1, r, lo, hi,x,y);
}
void query(int node, int l, int r)
{
	if(l > r)
	{
		return;
	}
	if(l == r)
	{
		cout << tree[node][v[l]] << ' ';
		return;
	}
	push(node);
	int mid = ( l + r ) >> 1;
	query(2*node,l,mid);
	query(2*node+1,mid+1,r);
}


int main()
{
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> v[i];
	}
	build(1,1,n);
	int q;
	cin >> q;
	while(q--)
	{
		int l,r,x,y;
		cin >> l >> r >> x >> y;
		update(1,1,n,l,r,x,y);
		
	}
	query(1,1,n);
	cout << '\n';
	return 0;
}
