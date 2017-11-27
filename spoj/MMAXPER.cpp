#include<bits/stdc++.h>
using namespace std;
int dp[1005][2];
int w[1005];
int h[1005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> w[i] >> h[i];
		if(i == 0)
		{
			dp[0][0] = w[0];
			dp[0][1] = h[0];
		}
		else
		{
			dp[i][0] = max( dp[i-1][0] + abs( h[i]-h[i-1] ), dp[i-1][1] + abs( h[i]-w[i-1] ) )+ w[i];
			
			dp[i][1] = max( dp[i-1][0] + abs( w[i]-h[i-1] ), dp[i-1][1] + abs( w[i]-w[i-1] ) ) + h[i];
		}
	}
	cout << max(dp[n-1][0],dp[n-1][1]) << '\n';
	return 0;
}
