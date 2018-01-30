#include<bits/stdc++.h>
using namespace std;
pair<long long, long long>v[15];
int main()
{
	int n;
	long long k;
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %lld",&n,&k);
		for(int i = 0 ; i < n ; i++)
			scanf("%lld %lld",&v[i].first, &v[i].second);
		long long ans = 0;
		for(int mask = 1; mask < (1 << n); mask++)
		{
			long long c = 0;
			long long w = 0;
			for(int i = 0; i < n; i++)
			{
				if(mask & (1 << i))
				{
					c += v[i].first;
					w += v[i].second;
				}
			}
			if(c <= k)
				ans = max(ans,w);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
