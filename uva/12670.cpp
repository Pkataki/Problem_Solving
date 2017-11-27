#include<bits/stdc++.h>
using namespace std;
int cont;
int num[100];
void gen(long long x)
{
	cont = 0;
	while(x)
	{
		num[cont] = x%2LL;
		cont++;
		x /= 2LL;
	}
}
long long dp[100][2][100];
long long solve(int pos, int menor, int sum)
{
	if(pos == -1)
		return sum;
	if(dp[pos][menor][sum] != -1)
		return dp[pos][menor][sum];
	
	long long ans = 0;
	if(!menor)
	{
		if(num[pos] == 0)
		{
			ans +=solve(pos-1,0,sum);
		}
		else
		{
			ans += solve(pos-1,1,sum) + solve(pos-1,0,sum+1);
		}
	}
	else
	{
		ans += solve(pos-1,menor,sum) + solve(pos-1,menor,sum+1);
	}
	return dp[pos][menor][sum] = ans;
}
main()
{
	long long a,b;
	while(scanf("%lld %lld",&a,&b) != EOF)
	{
		memset(dp,-1,sizeof(dp));
		gen(a-1);
		long long ans = solve(cont-1,0,0);
		memset(dp,-1,sizeof(dp));
		gen(b);
		//cout << solve(cont-1,0,0);
		printf("%lld\n",solve(cont-1,0,0) - ans);
	}
}
