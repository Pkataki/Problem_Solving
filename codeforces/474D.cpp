#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int dp[100005];
int main()
{
	int t,k;
	scanf("%d %d",&t,&k);
	dp[0] = 1;
	for(int i = 1; i <= 100000; i++)
	{
		dp[i] = dp[i-1];	
		if(i >= k)
			dp[i] += dp[i-k];	
		dp[i] %= mod;
	}
	for(int i = 1; i <= 100000; i++)
	{
		dp[i] += dp[i-1];	
		dp[i] %= mod;
	}
	while(t--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",(dp[b]-dp[a-1]+mod)%mod);
	}
}
