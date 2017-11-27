#include<bits/stdc++.h>
using namespace std;
int dp[110][1100];
int graph[110][110];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,s,e,t;
	while(cin >>n >> s >> e >>t && n && s && e && t)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cin >> graph[i][j];
			}
		}
		for(int i = 0; i < n; i++)
			dp[i][1] = graph[s-1][i];

		for(int ti = 2; ti <= t; ti++)
		{
			for(int i = 0; i < n; i++)
			{
				dp[i][ti] = 0;
				for(int j = 0; j < n; j++)
				{
					dp[i][ti]=max(dp[i][ti], dp[j][ti-1] + graph[j][i]);
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < e; i++)
		{
			int a;
			cin >> a;
			ans = max(ans,dp[a-1][t]);
		}
		cout << ans << '\n';
	}
}
