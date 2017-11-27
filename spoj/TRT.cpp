#include<bits/stdc++.h>
using namespace std;
long long dp[2005][2005];
int n;
long long v[2005];
long long solve(int i, int j)
{
	if(i > j)
		return 0;
	if(~dp[i][j])
		return dp[i][j];
	long long year = n - (j-i+1) + 1;
	
	return dp[i][j] = max(solve(i+1,j)+year*v[i],solve(i,j-1)+year*v[j]);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%lld",&v[i]);
	}
	printf("%lld\n",solve(0,n-1));
	return 0;
}
