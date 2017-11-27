#include<bits/stdc++.h>
using namespace std;
long long sum[5005];
int n,m,k;
long long dp[5005][5005];
long long solve(int at, int k)
{
	if(k == 0)
		return 0;
	if(at == n+1)
		return -(1LL << 60);
	if(dp[at][k] != -1LL)
		return dp[at][k];
	long long &ans = dp[at][k];
	ans = 0LL;
	if(at + m -1 <= n)
	{
		ans = solve(at+m,k-1) + sum[at+m-1] - sum[at-1];
	}
	ans = max(ans, solve(at+1,k));
	return ans;
}
int main()
{
	memset(dp,-1LL,sizeof(dp));
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
	{
		long long a;
		scanf("%lld",&a);
		sum[i] = sum[i-1] + a;
	}
	printf("%I64d\n",solve(1,k));
}
