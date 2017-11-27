#include<bits/stdc++.h>
using namespace std;
int a[3005];
int b[3005];
int c[3005];
int dp[3005][3];
int n;
int solve(int pos, int at)
{
	if(pos == n-1)
	{
		if(at)
			return b[pos];
		else
			return a[pos];
	}
	if(dp[pos][at] != -1)
		return dp[pos][at];
	int ans = 0;	
	if(at)
	{
		ans = max(solve(pos+1, 1) + b[pos], solve(pos+1,0) + c[pos]);
	}
	else
	{
		ans = max(solve(pos+1, 1) + a[pos], solve(pos+1,0) + b[pos]);
	}

	return dp[pos][at] = ans;
}
int main()
{
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	
	for(int i = 0; i < n; i++)
		scanf("%d",&b[i]);
	
	for(int i = 0; i < n; i++)
		scanf("%d",&c[i]);

	cout << solve(0,0) << '\n';
}
