#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
string s;
int INF;
int solve(int i, int j)
{
	if(i >= j)
		return 0;
	if(dp[i][j] != INF)
		return dp[i][j];
	int ans = 0;
	if(s[i] == s[j])
	{
		ans = solve(i+1,j-1);
	}
	else
	{
		ans = min(solve(i+1,j)+1,min(solve(i,j-1)+1,solve(i+1,j-1)+1));
	}
	return dp[i][j]= ans;
}
main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		memset(dp,0x3f3f3f,sizeof(dp));
		INF = dp[0][0];
		cin >> s;
		cout << "Case " << i+1 << ": " <<solve(0,s.size()-1)  << "\n";
	}
}
