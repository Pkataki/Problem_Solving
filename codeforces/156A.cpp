#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int main()
{
	string s;
	string t;
	cin >> s >> t;
	s = ' ' + s;
	t = ' ' + t;
	int ans = 0;
	for(int i = 1; i < s.size(); i++)
	{
		for(int j = 1; j < t.size(); j++)
		{
			dp[i][j] = dp[i-1][j-1] + (s[i] == t[j]);
			ans = max(ans,dp[i][j]);
		}
	}
	cout << ((t.size()-1) - ans) << '\n';
}

