#include<bits/stdc++.h>
using namespace std;
int dp[100010];
int last_app[100];
const int mod = 1000000007;
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		string s;
		cin >> s;
		memset(dp,0,sizeof(dp));
		memset(last_app,0,sizeof(last_app));
		dp[0] = 1;
		for(int i = 1; i <= s.size(); i++)
		{
			int last = last_app[s[i-1]];

			dp[i] = (dp[i-1] * 2)%mod;
			
			if(last)
				dp[i] = ( dp[i] - dp[last-1] + mod ) % mod;
			
			last_app[s[i-1]] = i;
		}
		cout << dp[s.size()] << '\n';
	}
}
