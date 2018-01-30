#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
struct node
{
	int ls;
	int rs;
	int cont;
}tree[MAXN*20];

int root[MAXN];

int sz;

void update(int &n, int pre, int l, int r, int pos)
{
	if(l > r)
		return;
	n = ++sz;
	tree[n] = tree[pre];
	if(l == r && pos == l)
	{
		tree[n].cont++;
		tree[n].ls = tree[n].rs = 0;
		return;
	}
	int mid = (l+r ) >> 1;
	if(pos <= mid)
		update(tree[n].ls, tree[pre].ls, l , mid, pos);
	else
		update(tree[n].rs, tree[pre].rs, mid+1 , r, pos);

	tree[n].cont = tree[tree[n].ls].cont  + tree[tree[n].rs].cont;
}

int query(int r1, int r2, int l, int r, int k)
{
	int count = tree[r1].cont - tree[r2].cont;
	if(count <= k)
		return -1;
	if(l == r)
		return l;
	int mid = (l + r) >> 1;
	int a =  query(tree[r1].ls, tree[r2].ls, l, mid, k);
	if(a != -1)
		return a;
	return query(tree[r1].rs, tree[r2].rs, mid+1, r, k);
}
int v[MAXN];
int main()
{
	int n;
	
	int q; 
	scanf("%d %d",&n,&q);
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d",&v[i]);
	}
	update(root[1], 0 , 1, n, v[1]);
	for(int i = 2; i <= n; i++)
	{
		update(root[i], root[i-1], 1, n, v[i]);
	}
	while(q--)
	{
		int l,r,k;
		scanf("%d %d %d",&l,&r,&k);
		int ans = query(root[r], root[l-1], 1, n, (r-l+1)/k );
		printf("%d\n",ans);
	}
	
	return 0;
}
