#include<bits/stdc++.h>
using namespace std;
struct no
{
	int prefix,suffix,sum,maxsum;
	
	no()
	{
		prefix = suffix = sum = maxsum = INT_MIN;
	}
};
no tree[10*50005];
int v[50005];
no merge(no a, no b)
{
	no ans;
	ans.sum = a.sum+b.sum;
	ans.prefix = max(a.prefix, a.sum+b.prefix);
	ans.suffix = max(a.suffix+b.sum,b.suffix);
	ans.maxsum = max(max(a.maxsum,b.maxsum),a.suffix+b.prefix);
	return ans;
}
void build(int node, int l, int r)
{
	if(l > r)	
		return;
	if(l == r)
	{
		tree[node].prefix = tree[node].suffix = tree[node].maxsum = tree[node].sum = v[l];
		return;
	}
	int mid = (l+r) >> 1;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	tree[node] = merge(tree[node*2],tree[node*2 + 1]);
}
no query(int node, int l ,int r, int x, int y)
{

	if(l > r || l > y || r < x)
	{
		no k;
		k.prefix = k.suffix = k.maxsum = k.sum = INT_MIN;
		return k;
	}
	if(x <= l && r <= y)
	{
		return tree[node];
	}
	int mid = (l+r) >> 1;
	no a,b;
	a = query(2*node,l,mid,x,y);
	b = query(2*node+1,mid+1,r,x,y);
	if(a.maxsum == INT_MIN)
		return b;
	if(b.maxsum == INT_MIN)
		return a;
	return merge(a,b);
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n ; i++)
		scanf("%d",&v[i]);
	build(1,0,n-1);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		x--;
		y--;
		printf("%d\n",query(1,0,n-1,x,y).maxsum );
	}
	return 0;
}
