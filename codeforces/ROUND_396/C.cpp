#include<bits/stdc++.h>
using namespace std;
int dp[1003];
int dp2[1003];
int accum[27];
const int mod = 1000000007;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 'a'; i <= 'z'; i++)
	{
		cin >> accum[i - 'a'];
	}
	dp[0] = 1;
	dp2[0] = 0;
	int l = 0;
	for(int i = 1; i <= n; i++)
	{
		int k = 0;
		dp2[i] = n;
		for(int x = i-1 ;x >= 0; x--)
		{
			k = max(k, i - accum[s[x]- 'a']);
			if(k > x)
				continue;
			dp[i] = (dp[i] + dp[x]) % mod;
			dp2[i] = min(dp2[i],dp2[x] +1 );
			l = max(l,i-x);
		}	
	}
	cout << dp[n] << '\n';
	cout << l << '\n';
	cout << dp2[n] << '\n';
	return 0;
}
