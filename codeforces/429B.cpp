#include<bits/stdc++.h>
using namespace std;
long long mat[1005][1005];
long long dp[4][1005][1005];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n ; i++)
		for(int j = 1; j <= m ; j++)
			cin >> mat[i][j];


	for(int i = 1; i <= n ; i++)
		for(int j = 1; j <= m ; j++)
			dp[0][i][j] = mat[i][j] + max(dp[0][i][j-1],dp[0][i-1][j]);
	
	for(int i = 1; i <= n ; i++)
		for(int j = m; j >= 1 ; j--)
			dp[1][i][j] = mat[i][j] + max(dp[1][i][j+1],dp[1][i-1][j]);

	for(int i = n; i >= 1 ; i--)
		for(int j = 1; j <= m ; j++)
			dp[2][i][j] = mat[i][j] + max(dp[2][i][j-1],dp[2][i+1][j]);

	for(int i = n; i >= 1 ; i--)
		for(int j = m; j >= 1 ; j--)
			dp[3][i][j] = mat[i][j] + max(dp[3][i][j+1],dp[3][i+1][j]);

	long long ans = 0;
	for(int i = 2; i <= n-1 ; i++)
	{
		for(int j = 2; j <= m-1; j++)
		{
			ans = max(ans, dp[0][i-1][j] + dp[3][i+1][j] + dp[1][i][j+1] + dp[2][i][j-1]);
			ans = max(ans, dp[0][i][j-1] + dp[3][i][j+1] + dp[1][i-1][j] + dp[2][i+1][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}
