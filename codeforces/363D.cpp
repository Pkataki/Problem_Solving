#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a;
long long b[100005];
long long p[100005];
bool solve(int lim)
{
	long long r = 0;
	for(int i = 0; i < lim; i++)
	{
		if(p[lim-i-1] > b[n-i-1])
		{
			r += (p[lim-i-1] - b[n-i-1]);	
		}
	}
	if(r > a)
		return 0;
	return 1;
}
int main()
{
	scanf("%d %d %I64d",&n,&m,&a);
	for(int i = 0; i < n; i++)
		scanf("%I64d",&b[i]);
	for(int i = 0; i < m; i++)
		scanf("%I64d",&p[i]);

	sort(b,b+n);
	sort(p,p+m);
	int l,r;
	l = 0;
	r = min(n,m);
	while(l <= r)
	{
		int mid = ( l + r) >> 1;
		if(solve(mid))
		{
			l = mid + 1;
		}
		else
			r = mid-1;
	}
	long long sum = 0;
	for(int i = 0; i < r; i++)
	{
		sum += p[i];
	}
	sum = max(0LL,sum-a);
	printf("%d %I64d\n",r,sum);
}
