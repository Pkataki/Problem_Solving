#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int v[105];
int solve(int l, int r)
{
	if(l > r)
		return 0;
	if(dp[l][r] != -1)
		return dp[l][r];
	int sum = 0;
	int ans = INT_MIN;
	dp[l][r] = 0;
	for(int i = l; i <= r; i++)
	{
		sum += v[i];
		ans = max(ans,sum-solve(i+1,r));
	}
	sum = 0;
	for(int i = r; i >= l; i--)
	{
		sum += v[i];
		ans = max(ans,sum - solve(l,i-1));
	}
	return dp[l][r] = ans;
}
int main()
{
	int n;
	ios_base::sync_with_stdio(0);
	while(cin >> n && n)
	{
		memset(dp,-1,sizeof(dp));
		for(int i = 0 ; i < n; i++)
			cin >> v[i];
		cout << solve(0,n-1) << '\n';
	}

	return 0;
}
