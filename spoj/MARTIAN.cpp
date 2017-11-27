#include<bits/stdc++.h>
using namespace std;
int y[505][505];
int b[505][505];
int dp[505][505];
int ac_y[505][505];
int ac_b[505][505];
int main()
{
	int n,m;
	while(cin >> n >> m && n && m)
	{
		for(int i =1 ; i <= n ;i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin >> y[i][j];
				ac_y[i][j] = 0;
				ac_b[i][j] = 0;
				dp[i][j] = 0;
			}
		}
		for(int i = 1; i <= m; i++)
		{
			ac_y[0][i] = 0;
			ac_b[0][i] = 0;
			dp[0][i] = 0;
		}
		for(int i = 1; i <= n; i++)
		{
			ac_y[i][0] = 0;
			ac_b[i][0] = 0;
			dp[i][0] = 0;
		}
		for(int i =1 ; i <= n ;i++)
		{
			for(int j = 1; j <= m; j++)
				cin >> b[i][j];
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				ac_b[i][j] = ac_b[i-1][j] + b[i][j];
				ac_y[i][j] = ac_y[i][j-1] + y[i][j];
				dp[i][j] = max(dp[i-1][j] + ac_y[i][j] , dp[i][j-1] + ac_b[i][j]);
				
			}
		}
		cout << dp[n][m] << '\n';
	}
	return 0;
}
