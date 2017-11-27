#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	long long dp[70][70][70];
	string a,b,c;
	while (t--)
	{
		cin >> a >> b >> c;
		memset(dp,0,sizeof(dp));
		for(int i = 0; i <= a.size() ; i++)
		{
			for(int j = 0; j <= b.size(); j++)
			{
				dp[0][i][j] = 1LL;
			}
		}
		for(int k = 1; k <= c.size() ; k++)
		{
			for(int i = 1; i <= a.size() ; i++)
			{
				for(int j = 1 ; j <= b.size() ; j++)
				{
					if(a[i-1] == c[k-1])
						dp[k][i][j] += dp[k-1][i-1][j];
					
					if(b[j-1] == c[k-1])
						dp[k][i][j] += dp[k-1][i][j-1];
				}
			}
		}
		long long ans = 0;
		for(int i = 0; i <= a.size() ; i++)
		{
			for(int j = 0; j <= b.size(); j++)
			{
				ans += dp[c.size()][i][j];
			}
		}
		cout << ans << '\n';		
	}
	return 0;
}
