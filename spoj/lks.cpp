#include <bits/stdc++.h>
using namespace std;
int v[505];
int w[505];
int dp[2][2000005];
int main()
{
	ios_base::sync_with_stdio(0);
	int n, k;
	
	cin >> k >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> v[i] >> w[i];
	}
	dp[0][0] = 0;
	dp[1][0] = 0;
	for(int i = 1; i <= n ; i++)
	{
		int idx = i&1;
		for(int j = 1; j <= k; j++)
		{
			dp[idx][j] = dp[1-idx][j];
			if(j-w[i] >= 0)
				dp[idx][j] = max(dp[idx][j], dp[1-idx][j - w[i]] + v[i]);
		}
	}
	cout << dp[n&1][k] << '\n';
}
