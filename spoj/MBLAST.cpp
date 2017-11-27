#include<bits/stdc++.h>
using namespace std;
int k;
string s,t;
long long dp[2005][2005];
int s_size,t_size;
long long solve(int i, int j)
{
	if(i == s_size && j == t_size)
		return 0LL;
	if(i == s_size)
		return (long long)k*(t_size - j);
	if(j == t_size)
		return (long long)k * (s_size - i);
	if(~dp[i][j])
		return dp[i][j];
	
	long long aux = (long long)abs(s[i] - t[j]);

	return dp[i][j] = min(aux + solve(i+1,j+1), (long long)k + min(solve(i, j+1),solve(i+1, j)));
}
main()
{
	memset(dp,-1,sizeof(dp));
	cin >> s >> t >> k;
	s_size = s.size();
	t_size = t.size();
	cout << solve(0,0) << '\n';
}
