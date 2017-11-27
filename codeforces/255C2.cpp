#include<bits/stdc++.h>
using namespace std;
int v[4010];
map<int,int>mapa;
int dp[5000][5000];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> v[i];

	int ans = 1;
	for(int i = 1; i <= n; i++ )
	{
		for(int j = i+1 ; j <= n; j++)
		{
			if(mapa.count(v[j]))
				dp[i][j] += dp[ mapa[v[j]] ][i] + 1;
			else
				dp[i][j] = 2;
			
			ans = max(ans,dp[i][j]);
		}
		mapa[v[i]] = i;
	}
	cout << ans << '\n';
	return 0;
}
