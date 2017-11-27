#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int s_size,t_size;
string s,t;
int solve(int i, int j)
{
	if(i == s_size)
		return ~(1 << 31) - 1;
	if(~dp[i][j])
		return dp[i][j];
			
	for(int k = j; k < t_size; k++)
	{
		if(s[i] == t[k])
		{
			dp[i][j] = min(solve(i+1,j), solve(i+1,k+1) + 1);
			return dp[i][j];
		}
	}

	return 1;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	cin >> s >> t;
	s_size = s.size();
	t_size = t.size();
	cout << solve(0,0) << '\n';
	return 0;
}
