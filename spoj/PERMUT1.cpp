#include<bits/stdc++.h>
using namespace std;
int dp[15][100];
int solve(int n, int k)
{
	if(n == 0)
		return 0;
	if(k == 0)
		return 1;
	if(~dp[n][k])
		return dp[n][k];
	
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(k-i >= 0)	
			sum += solve(n-1,k-i);
	}
	return dp[n][k] = sum;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	while(test--)
	{
		memset(dp,-1,sizeof(dp));
		int n,k;
		cin >> n >> k;
		cout << solve(n,k) << '\n';
	}

	return 0;
}
