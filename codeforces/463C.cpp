#include <bits/stdc++.h>
using namespace std;
long long mat[2005][2005];
long long dp[5005];
long long ds[5005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i  = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			scanf("%lld",&mat[i][j]);
			dp[i-j+n] += mat[i][j];
			ds[i+j] += mat[i][j];
		}
	}
	
	int x1,y1;
	int x2,y2;
	long long b1 = -1LL;
	long long b2 = -1LL;
	
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0; j < n; j++)
		{
			long long sum = dp[i-j+n] + ds[i+j] - mat[i][j];
			if((i+j) & 1)
			{
				if(b1 < sum)
				{
					b1 = sum;
					x1 = i;
					y1 = j;
				}
			}
			if(((i+j) & 1) == 0)
			{
				if(b2 < sum)
				{
					b2 = sum;
					x2 = i;
					y2 = j;
				}
			}
		}
	}
	printf("%lld\n",b1+b2);
	printf("%d %d %d %d\n",x1+1,y1+1,x2+1,y2+1);
	return 0;
}
