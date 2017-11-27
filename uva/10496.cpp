#include <bits/stdc++.h>
using namespace std;
int x[15];
int y[15];
int dp[15][(1 << 13) + 10];
int n;
int dist[15][15];
int solve(int pos, int mask)
{
	if(__builtin_popcount(mask) == n+1)
		return dist[pos][0];
	
	if(dp[pos][mask] != -1)
		return dp[pos][mask];
	
	int ans = (1 << 30);
	
	dp[pos][mask] = 0;
	
	for(int i = 0; i <= n; i++)
	{
		if((mask & (1 << i)) == 0)
		{
			ans = min(ans, solve( i, mask | (1 << i) ) + dist[pos][i] );
		}
	}
	return dp[pos][mask] = ans;
}
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		memset(dp,-1,sizeof(dp));
		int xsize,ysize;
		cin >> xsize >> ysize;
		cin >> x[0] >> y[0];
		memset(dist,0,sizeof(dist));
		cin >> n;
		for(int i = 1 ; i <= n ; i++)
			cin >> x[i] >> y[i];
		for(int i = 0; i <= n ; i++)
		{
			for(int j = 0; j <= n ; j++)
			{
				dist[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
			}
		}
		cout <<"The shortest path has length " <<  solve(0,1) << '\n';
	}
	
	return 0;
}
