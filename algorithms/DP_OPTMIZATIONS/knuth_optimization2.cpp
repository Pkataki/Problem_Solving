#include <bits/stdc++.h>
using namespace std;
long long v[10005];
long long dp[1010][1010];
int mid[1015][1015];
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF)
	{
		for(int i = 1; i <= m ; i++)
		{
			scanf("%lld",&v[i]);
		}
		v[++m] = n;
		m++;
        v[0] = 0;
		for(int i = 1; i < m-1 ; i++)
		{
			mid[i][i+1] = i;
			dp[i][i+1] = 0;
		}
		for(int s = 2; s < m; s++)
		{
			for(int l = 0; l + s < m; l++)
			{
				int r = l+s;
				
				int midl = mid[l][r-1];
				int midr = mid[l+1][r];
				dp[l][r] = (1LL << 60);
				for(int i = midl; i <= midr; i++)
				{
					long long ans = dp[l][i] + dp[i][r] + (v[r] - v[l]);
					if(ans < dp[l][r])
					{
						dp[l][r] = ans;
						mid[l][r] = i;
					}
				}
			}
		}
		printf("%lld\n",dp[0][m-1]);
	}
	return 0;
}