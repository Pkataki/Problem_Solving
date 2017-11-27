#include<bits/stdc++.h>
using namespace std;
map<int,int>mapa;
int dp[30005][500];
int n,d;
int solve(int pos, int des)
{
	if(pos > 30000)
	{
		return 0;
	}
	int nd = des - d + 250;
	if(dp[pos][nd] != -1)
		return dp[pos][nd];
	int ans = 0;
	if(des == 1)
	{
		ans = mapa[pos] + max(solve(pos+des+1,des+1),solve(pos+des,des));	
	}
	else
	{
		ans = mapa[pos] + max(solve(pos+des+1,des+1),max(solve(pos+des,des),solve(pos+des-1,des-1)));
	}
	return dp[pos][nd] = ans;
}	
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	scanf("%d",&d);
	for(int i = 0; i < n; i++)
	{
		int a;
		scanf("%d",&a);
		mapa[a]++;
	}
	printf("%d\n",solve(d,d));
}
