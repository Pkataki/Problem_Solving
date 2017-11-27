#include<bits/stdc++.h>
using namespace std;
long long dp[1005][1005][2];
int n;
long long v[1005];
long long solve(int i, int j, bool p)
{
	if(i == j)
	{
		if(p)
			return -v[i];
		else
			return v[i];
	}
	if(i > j)
		return 0;

	if(~dp[i][j][p])
		return dp[i][j][p];
	if(!p)
	{
		dp[i][j][p] = max(solve(i+1,j,p^1) + v[i], solve(i,j-1,p^1) + v[j]);	
	}
	else
	{
		if(v[i] >= v[j])
			dp[i][j][p] = solve(i+1,j,p^1) - v[i];
		else
			dp[i][j][p] = solve(i,j-1,p^1) - v[j];		
	}
	return dp[i][j][p];
}
int main()
{
	int g = 1;
	while(cin >> n && n)
	{
		memset(dp,-1,sizeof(dp));
		for(int i = 0; i < n; i++)
			cin >> v[i];
		cout << "In game " << g << ", the greedy strategy might lose by as many as " << solve(0,n-1,0) << " points.\n";
		g++;
	}
	return 0;
}
