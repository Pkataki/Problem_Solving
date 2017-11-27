#include <bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n,k;
		cin >> n >> k;
		int v[n];
		int v1[n];
		int dp[k+2][k+2];
		for(int i = 0 ; i <= k ; i++)
			for(int j = 0 ; j <= k ; j++)
				dp[i][j] = (1 << 30);
			
		for(int i = 0; i < n ; i++)
		{
			cin >> v[i] >> v1[i]; 
		}
		dp[0][0] = 0;
		int ans = INT_MAX;
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = v[i]; j <= k; j++)
			{
				for(int h = v1[i]; h <= k; h++)
				{
					dp[j][h] = min(dp[j][h], dp[j-v[i]][h-v1[i]] + 1);
				}
			}
		}
		for(int i = 0; i <= k ; i++)
			for(int j = 0; j <= k; j++)
				if(i *i + j*j == k * k)
					ans = min(ans,dp[i][j]);
		if(ans == (1 << 30))
			cout << "not possible\n";
		else
			cout << ans << '\n';

	}
	return 0;
}
