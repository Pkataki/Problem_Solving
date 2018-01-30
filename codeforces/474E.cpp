#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
typedef pair<int,int> pii;
pii tree[4*MAXN];
long long v[MAXN];
long long c[MAXN];
void update(int node, int l, int r, long long v, pii a)
{
	if(v < c[l] || c[r] < v)
		return;
	if(l == r)
	{
		tree[node] = max(tree[node], a);
		return;
	}
	int mid = (l + r) >> 1;
	update(2*node,l,mid,v,a);
	update(2*node+1,mid+1,r,v,a);
	tree[node] = max(tree[2*node],tree[2*node+1]);
}
pii query(int node, int l, int r, long long x, long long y)
{
	if (x > y) 
		return pii(0,-1);
    if (y < c[l] || c[r] < x)
    	return pii(0, -1);
	if(x <= c[l] && c[r] <= y)
	{
		return tree[node];
	}
	int mid = (l + r) >> 1;
	return max(query(2*node,l,mid,x,y),query(2*node+1,mid+1,r,x,y));
}
long long dp[MAXN];
int pre[MAXN];
const long long MA = 1000111000111000LL;
void print(int pos)
{
	if(pre[pos] == -1)
		return;
	print(pre[pos]);
	printf("%d ",pos);
	
}
int main()
{
	int n;
	long long d;
	memset(pre,-1,sizeof(pre));
	scanf("%d %lld",&n,&d);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld",&v[i]);
		c[i] = v[i];
	}
	sort(c+1,c+n+1);
	int sz = unique(c+1, c + n + 1) - c - 1;
	int last = -1;
	int ans = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		pii at = max(query(1,1,sz,1,v[i]-d),query(1,1,sz,v[i]+d, MA));
		int val = at.first + 1;
		int pos = at.second;
		pre[i] = pos;
		update(1,1,sz,v[i],pii(val,i));
		if(val > ans)
		{
			ans = val;
			last = i;
			 
		}
		
	}
	printf("%d\n",ans);
	print(last);
	puts("");
	return 0;
}