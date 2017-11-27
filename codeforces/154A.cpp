#include<bits/stdc++.h>
using namespace std;
int dp[30][100005];
int m;
string s;
int f[50][50];
int solve(int last, int pos)
{
	if(pos == m)
		return 0;
	if(dp[last][pos] != -1)
		return dp[last][pos];
	int ans = 0;
	ans = 1 + solve(last,pos+1);
	if( !f[last][s[pos] - 'a'] )
		ans = min(ans, solve(s[pos] - 'a',pos+1));
	
	return dp[last][pos] = ans;
}
int main()
{
	cin >> s;
	m = s.size();
	int n;
	cin >> n;
	for(int i = 0; i < n ; i++)
	{
		string t;
		cin >> t;
		f[t[0] - 'a'][t[1] - 'a'] = f[t[1] - 'a'][t[0] - 'a'] = 1;
	}
	memset(dp,-1,sizeof(dp));
	cout << solve(26,0) << '\n';

	return 0;
}
