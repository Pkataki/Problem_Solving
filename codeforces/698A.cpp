#include<bits/stdc++.h>
using namespace std;
int dp[110][5];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n ; i++)
	{
		int a;
		cin >> a;
		if(a & 1)
		{
			dp[i+1][1] = max(dp[i][0],dp[i][2])+1;
		}
		if(a & 2)
		{
			dp[i+1][2] = max(dp[i][0],dp[i][1])+1;	
		}
		dp[i+1][0] = dp[i][0];
		dp[i+1][0] = max(dp[i+1][0],max(dp[i][1], dp[i][2]));
	}
	dp[n+1][0] = dp[n][0];
	dp[n+1][0] = max(dp[n+1][0],max(dp[n][1], dp[n][2]));
/*	for(int i = 1; i<= n+1; i++)
	{
		cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << '\n';
	}*/
	cout << n - dp[n+1][0] << '\n';
	return 0;
}
