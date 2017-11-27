#include<bits/stdc++.h>
using namespace std;
int tree[800005];
void build(int node, int l, int r)
{
	if(l == r)
	{
		tree[node] = 1;
		return;
	}
	int mid = (l+r) >> 1;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	tree[node] = tree[2*node] + tree[2*node+1];
}
int query(int node, int l , int r, int v)
{
	if(v > tree[node])
		return -1;
	if(l == r)
	{
		return l;
	}
	int mid = (l+r) >> 1;
	if(tree[2*node] >= v)
		return query(2*node,l,mid,v);
	else
		return query(2*node+1,mid+1,r,v-tree[2*node]);
}
void remove(int node, int l, int r, int p)
{
	if(l == r)
	{
		tree[node] = 0;
		return;
	}
	int mid = (l+r) >> 1;
	if(p <= mid)
		remove(2*node,l,mid,p);
	else
		remove(2*node+1,mid+1,r,p);
	tree[node] = tree[2*node] + tree[2*node+1];
}
int v[200005];
int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> v[i];
		}
		build(1,0,n-1);
		int ans[n];
		for(int i = 0; i < n ; i++)
			ans[i] = i;
		int res[n];
		for(int i = n-1; i >= 0 ; i--)
		{
			res[i] = query(1,0,n-1,i+1-v[i]);
			remove(1,0,n-1,res[i]);
		}
		cout << ans[res[0]]+1;
		for(int i = 1 ; i < n ; i++)
			cout <<' '<< ans[res[i]]+1;
		cout << '\n';
	}
	return 0;
}
