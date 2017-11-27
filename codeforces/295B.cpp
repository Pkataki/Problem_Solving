#include<bits/stdc++.h>
using namespace std;
long long dp[505][505];
int v[505];
int n;
void update_graph(int u)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			dp[i][j] = min(dp[i][j], dp[i][u] + dp[u][j]);
		}
	}
}
long long sum(int j)
{
	long long ans = 0;
	for(int i = n-1; i >= j; i--)
	{
		for(int k = n-1;  k >= j; k--)
		{
			int u = v[i]-1;	
			int x = v[k]-1;
			if(u != x)
				ans += dp[u][x];
		}
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%I64d",&dp[i][j]);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&v[i]);
	}
	long long ans[n];
	for(int i = n-1; i >= 0; i--)
	{
		int u = v[i];
		update_graph(u-1);
		ans[i] = sum(i);
	}
	printf("%I64d",ans[0]);
	for(int i = 1; i < n; i++)
		printf(" %I64d",ans[i]);
	puts("");

}
