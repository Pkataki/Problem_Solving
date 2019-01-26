#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4005;
int dp[MAXN][MAXN];
int opt[MAXN][MAXN];
int sum[MAXN][MAXN];

int cost(int i, int j)
{
	return sum[j][j] - sum[i][j] - sum[j][i] + sum[i][i]; 
}
int main()
{
	int n,k;
	n = get();
	k = get();
	for(int i = 1; i <= n ; i++)
	{
		for(int j = 1; j <= n ; j++)
		{
			sum[i][j] = get();
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	for(int i  = 1; i <= n ; i++)
	{
		dp[i][1] = cost(0, i);
		opt[1][i] = 1;
	}
	int aux = 0;
	for(int i = 2; i <= k ; i++)
	{
		for(int j = n; j >= 1; j--)
		{
			dp[j][i] = INT_MAX;
			opt[n+1][i] = n;
			for(int l = opt[j][i-1]; l <= opt[j+1][i]; l++)
			{
				aux = cost(l,j);
				if( dp[j][i] > dp[l][i-1] + aux)
				{
					dp[j][i] = dp[l][i-1] + aux;
					opt[j][i] = l;
				}
			}
		}
	}
	printf("%d\n", dp[n][k] >> 1);

	return 0;
}
