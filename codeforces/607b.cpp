#include<bits/stdc++.h>
using namespace std;
int v[505];
int dp[605][605];
int solve(int l ,int r)
{
	if(l > r)
		return 0;
	if(l == r)
		return 1;
	if(l == r-1)
	{
		if(v[l] == v[r])
			return dp[l][r] = 1;
		else
			return dp[l][r] = 2;
	}
	if(~dp[l][r])
		return dp[l][r];
	dp[l][r] = (1 << 30);
	int ans = (1<< 30);
	if(v[l] == v[r])
		ans = solve(l+1,r-1);
	for(int i = l; i <= r; i++)
	{
		ans = min(ans, solve(l,i) + solve(i+1,r) );
	}
	return dp[l][r] = ans;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i< n; i++)
		cin >> v[i];
	memset(dp,-1,sizeof(dp));
	cout << solve(0,n-1) << '\n';
	return 0;
}
