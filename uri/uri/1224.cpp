#include<bits/stdc++.h>
using namespace std;
long long v[100005];
long long dp[2][100005];
int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		memset(dp,0,sizeof(dp));
		for(int i = 0 ; i < n ;i++)
			scanf("%lld",&v[i]);

		for(int i = 0; i < n-1; i++)
		{
			dp[0][i] = max(v[i],v[i+1]);
		}
		int cur = 0;
		int last = 1;
		for(int len = 4; len <= n; len += 2)
		{
			last = cur;
			cur = 1 - cur;
			for(int i = 0, j = len-1; j < n; i++, j++)
			{
				dp[cur][i] = max(v[i] + min(dp[last][i+1], dp[last][i+2]),
								 v[j] + min(dp[last][i]  , dp[last][i+1]));
			}
		}
		printf("%lld\n",dp[cur][0]);

	}
	return 0;
}
