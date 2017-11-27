#include<bits/stdc++.h>
using namespace std;
long long v[100005];
long long dp[100005][3][2];
int n;
long long solve(int pos, int fim, int par)
{
	if(pos == n-1)
	{
		return 0LL;
	}
	if(dp[pos][fim][par] != -1LL)
		return dp[pos][fim][par];
	long long ans = 0;
	dp[pos][fim][par] = 0LL;
	if(fim == 0)
	{
		ans = solve(pos+1, 1, 1) + llabs(v[pos]-v[pos+1]); 		
		ans = max(ans,solve(pos+1,0,0)); 
	}
	else if(fim)
	{
		ans = solve(pos+1,1,par^1) + llabs(v[pos]-v[pos+1]) * ((par == 1) ? (-1LL) : (1LL)); 		
		ans = max(ans,solve(pos+1,2,1));
	}
	else
	{
		return dp[pos][fim][par] = 0;
	}
	return dp[pos][fim][par] = ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	memset(dp,-1LL,sizeof(dp));
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cout << solve(0,0,0) << '\n';

}
