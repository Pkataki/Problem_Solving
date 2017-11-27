#include<bits/stdc++.h>
using namespace std;
int dp[5005][5005];
char s[5005];
int solve(int i, int j)
{
	if(i > j)
		return 0;
	if(dp[i][j] != dp[5004][5004])
		return dp[i][j];
	int ans = 0;
	if(s[i] != s[j])
	{
		ans = min(solve(i+1,j)+1,solve(i,j-1)+1);
	}
	else
	{
		ans = solve(i+1,j-1);
	}
	return dp[i][j] = ans;
}
main()
{
	memset(dp,0x3f3f,sizeof(dp));
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	cin >> s;
	cout << solve(0,n-1) << "\n";
}
