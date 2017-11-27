#include <bits/stdc++.h>
using namespace std;
int v[100005];
int dp[100005][5];
const int neg_inf = INT_MIN+1000;
int main()
{
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> v[i];
	}
	dp[1][abs(v[1]) % 2] = v[1];
	dp[1][!(abs(v[1]) % 2)] = neg_inf;
	for(int i = 2; i <= n ; i++)
	{
		dp[i][0] = neg_inf;
		dp[i][1] = neg_inf;
		
		if(dp[i - 1][0] != neg_inf)
			dp[i][0] = dp[i - 1][0];

		if(dp[i - 1][1] != neg_inf)
			dp[i][1] = dp[i - 1][1];
		
		if(abs(v[i]) % 2)
		{
			dp[i][1] = max(dp[i][1] , v[i]);

			dp[i][0] = max(dp[i][0], (dp[i - 1][1] != neg_inf ? dp[i - 1][1] + v[i] : neg_inf));
			
			dp[i][1] = max(dp[i][1], (dp[i - 1][0] != neg_inf ? dp[i - 1][0] + v[i] : neg_inf));
		}
		else
		{
			dp[i][0] = max(dp[i][0] , v[i]);
			
			dp[i][0] = max(dp[i][0], (dp[i - 1][0] != neg_inf ? dp[i - 1][0] + v[i] : neg_inf));
			
			dp[i][1] = max(dp[i][1], (dp[i - 1][1] != neg_inf ? dp[i - 1][1] + v[i] : neg_inf));
		}
	}
	cout << dp[n][1] << '\n';
	return 0;
}
