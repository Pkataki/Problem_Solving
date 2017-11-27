#include<bits/stdc++.h>
using namespace std;
int dp[105][2];
const int mod = 1000000007;
int main()
{
	int n,k,d;
	scanf("%d %d %d",&n,&k,&d);
	dp[0][0] = 1;
	for(int w = 1; w <= n; w++)
	{
		for(int i = 1; i <= k; i++)	
		{
			if(w-i < 0)
				break;
			if(i < d)
			{
				dp[w][0] = (dp[w][0] + dp[w-i][0])%mod;
				dp[w][1] = (dp[w][1] + dp[w-i][1])%mod;
			}
			else
			{
				dp[w][1] = (dp[w][1] + dp[w-i][0])%mod;
				dp[w][1] = (dp[w][1] + dp[w-i][1])%mod;
			}
		}
	}
	printf("%d\n",dp[n][1]);
}
