#include<bits/stdc++.h>
using namespace std;
double dp[560][3400];

int main()
{
	for(int i = 1 ; i < 7; i++)
		dp[1][i] = (double)1.0/6.0;
	
	for(int i = 2; i <= 550; i++)
	{
		for(int j = 1; j <= 3300; j++)
		{
			for(int k = 1; k < 7; k++)
			{
				if((j - k) >= 0)
					dp[i][j] += (dp[i-1][j-k]/6.0);
			}
		}
	}


	int n,m,test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&n,&m);
		if(n > 550 || m > 3300)
		{
			printf("0\n");
			continue;
		}
		else
		{
			long long ans = dp[n][m] * 100.0;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
