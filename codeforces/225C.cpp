#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF=10000000;

char s[1001][1001];
int cost[2][1002];

int n,m;
int x,y;

int dp[2][1001][1001];

int solve(int st, int l, int r)
{
	if(dp[st][l][r] !=-1)
		return dp[st][l][r];
	
	
	if(r == m)
	{
		if(r-l == 0 || x <= r-l && r-l <= y)
			return dp[st][l][r] = 0;
		else
			return dp[st][l][r] = INF;
	}
	else
	{
		if(r - l + 1 < x)
			dp[st][l][r] = solve(st,l, r+1 ) + cost[st][r+1] ;
		else if(x <= r-l+1 && r-l+1 < y)
			dp[st][l][r] = min(solve(st,l,r+1) + cost[st][r+1], solve(1-st, r+1, r+1) + cost[1-st][r+1]);
		else
			dp[st][l][r] = solve(1-st,r+1,r+1) + cost[1-st][r+1];

	}
	
	return dp[st][l][r];
}


int main()
{
	cin >> n >> m >> x >> y;
	for(int i = 0; i < n; i++)
		scanf("%s",s[i]);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if(s[i][j]=='#')
				cost[0][j]++;
			else
				cost[1][j]++;
		}
	
	memset(dp,-1,sizeof(dp));
	printf("%d\n",min(solve(0,0,0)+cost[0][0],solve(1,0,0)+cost[1][0]));
}
