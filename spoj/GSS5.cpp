#include<bits/stdc++.h>
using namespace std;
struct data
{
	int pref,suf,sum,best;
}tree[500005];
data combine(data l, data r)
{
	data res;
	res.sum = l.sum + r.sum;
	res.pref = max(l.pref, l.sum + r.pref);
	res.suf = max(r.suf, r.sum + l.suf);
	res.best = max(max( max(l.best, r.best), max(l.suf + r.pref, res.sum)),max(res.pref,res.suf));
	return res;
}
int v[100005];
void build(int node, int l,int r)
{
	if(l == r)
	{
		tree[node].sum = tree[node].best = tree[node].pref = tree[node].suf = v[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	tree[node] = combine(tree[2*node],tree[2*node+1]);
}
data query(int node, int l, int r, int x, int y)
{
	if( l > y || r < x)
	{
		data aux;
		aux.pref = aux.suf = aux.best = -10000000;
		aux.sum = 0;
		return aux;
	}
	if(l >= x && r <= y)
	{
		return tree[node];
	}
	int mid = (l + r) >> 1;
	data left = query(2*node,l,mid,x,y);
	data right = query(2*node+1,mid+1,r,x,y);

	return combine(left,right);
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%d",&v[i]);
		
		build(1,0,n-1);
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int x1,x2,y1,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			x1--;
			y1--;
			x2--;
			y2--;
			int ans = 0;
			if(y1 < x2)
			{
				ans = query(1,0,n-1,x1,y1).suf;
				ans += query(1,0,n-1,y1+1,x2-1).sum;
				ans += query(1,0,n-1,x2,y2).pref;
			}
			else
			{
				ans = max(query(1,0,n-1,x1,x2-1).suf + query(1,0,n-1,x2,y2).pref , query(1,0,n-1,x1,y1).suf+ query(1,0,n-1,y1+1,y2).pref);
				ans = max(ans,query(1,0,n-1,x2, y1).best);
			}
			printf("%d\n",ans);
		}
	}
}
