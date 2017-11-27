#include<bits/stdc++.h>
using namespace std;
long long v[100005];
long long v1[100005];
long long sum[100005];
long long sum1[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%lld",&v[i]);
		v1[i] = v[i];
	}
	sort(v1,v1+n);
	sum[0] = v[0];
	for(int i = 1; i < n; i++)
	{
		sum[i] = sum[i-1] + v[i];
	}
	sum1[0] = v1[0];
	for(int i = 1; i < n; i++)
	{
		sum1[i] = sum1[i-1] + v1[i];
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int t,a,b;
		scanf("%d %d %d",&t,&a,&b);
		a--;
		b--;
		if(t == 1)
		{
			printf("%lld\n",sum[b] - sum[a-1]);
		}
		else
		{
			printf("%lld\n",sum1[b] - sum1[a-1]);
		}
	}
}
