#include<bits/stdc++.h>
using namespace std;
int dp[2][1005];
int main()
{
	int n;
	while(cin >> n)
	{
		vector<pair<int,int> >v(n);
		for(int i = 0; i < n; i++)
		{
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(),v.end());
		memset(dp,0,sizeof(dp));
		for(int i = 0; i < n; i++)
		{
			dp[0][i] = dp[1][i] = 1;
			for(int j = 0; j < i ;j++)
			{
				if(v[j].first < v[i].first)
				{
					if(v[i].second - v[j].second == 2)
						dp[0][i] = max(dp[0][i], dp[1][j]+1);
					
					else if(v[j].second - v[i].second == 2)
						dp[1][i] = max(dp[1][i], dp[0][j]+1);
				}
			}
		}
		int ans = 1;
		for(int i = 0; i < n; i++)
			ans = max(ans, max(dp[0][i], dp[1][i]));
		cout <<ans << '\n';
	}
	return 0;
}
