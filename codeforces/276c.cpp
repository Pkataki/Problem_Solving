#include<bits/stdc++.h>
using namespace std;
long long bit[200005];
long long get(int idx)
{
	long long sum = 0;
	while(idx)
	{
		sum += bit[idx];
		idx -= idx & (-idx); 
	}
	return sum;
}
void update(int idx, long long val)
{
	while(idx < 200005)
	{
		bit[idx] += val;
		idx += idx & -idx;
	}
}
int main()
{
	int n;
	int q;
	scanf("%d %d",&n,&q);
	int v[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&v[i]);
	}
	sort(v,v+n);

	for(int i = 0; i < q; i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		update(l,1);
		update(r+1,-1);
	}

	long long fre[n];
	for(int i = 1; i <= n; i++)
	{
		fre[i-1] = get(i);	
	}
	long long ans = 0;
	sort(fre,fre+n);
	for(int i = n-1; i  >= 0; i--)
	{
		ans += (long long)v[i]*(long long)fre[i];
	}
	printf("%lld\n",ans);
}
