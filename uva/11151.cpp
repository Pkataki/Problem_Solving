#include<bits/stdc++.h>
using namespace std;
int dp[1055][1055];
char s[1010];
int solve(int i,int j)
{
	if(i == j)
		return 1;
	if(i > j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	int ans = 0;
	if(s[i] == s[j])
	{
		ans = max(ans,solve(i+1,j-1)+2);
	}
	else
	{
		ans = max(solve(i+1,j),solve(i,j-1));
	}
	return dp[i][j] = ans;
}
main()
{
	int test;
	cin >> test;
	cin.ignore();
	while(test--)
	{
		memset(dp,-1,sizeof(dp));
		cin.getline(s,1010);
		printf("%d\n" ,solve(0,strlen(s)-1));	
	}
}
