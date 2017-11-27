#include<bits/stdc++.h>
using namespace std;
int n;
int dp[105][105];
int v[105];
int sum(int l, int r)
{
	int ans = 0;
	for(int i = l; i <= r; i++)
		ans = (ans + v[i]) %100;
	return ans;
}
int solve(int l, int r)
{
	if(l == r)
		return 0;
	if(~dp[l][r])
		return dp[l][r];
	
	int ans = 1 - ~(1 << 29);
	for(int k = l ;k < r; k++)
	{
		ans = min(ans,solve(l,k)+solve(k+1,r)+sum(l,k)*sum(k+1,r));		
	}
	return dp[l][r] = ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	while(cin >> n && n)
	{
		memset(dp,-1,sizeof(dp));
		for(int i = 0; i < n; i++)
			cin >> v[i];
		cout << solve(0,n-1) << '\n';
	}

}
