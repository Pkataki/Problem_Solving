#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	while(test--)
	{
		int n,m;
		cin >> n >> m;
		int dp[n][m];
		int mat[n][m];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> mat[i][j];
				if(!i)
					dp[i][j] = mat[i][j];
				else
					dp[i][j] = 0;
			}
		}
		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(j-1 >= 0)
					dp[i][j] =  max(dp[i][j], mat[i][j] + dp[i-1][j-1]);
				if(j+1 < m)
					dp[i][j] = max(dp[i][j],mat[i][j] + dp[i-1][j+1]);
				
				dp[i][j] = max(dp[i][j], mat[i][j] + dp[i-1][j]);
			}
		}
		int ans = 0;
		for(int i = 0; i < m; i++)
		{
			ans = max(ans,dp[n-1][i]);
		}
		cout << ans << '\n';
	}

}
