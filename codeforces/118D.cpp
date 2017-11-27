#include<bits/stdc++.h>
using namespace std;
int n1,n2,k1,k2;
long long mod = 100000000;
long long dp[105][105][2];
long long ref1;
long long solve(int seg1, int seg2, bool t)
{
	if(seg1 + seg2 == 0)
	{		
		return 1LL;
	}
	if(dp[seg1][seg2][t] != -1LL)
		return dp[seg1][seg2][t];
	
	long long ans = 0LL;
	
	dp[seg1][seg2][t] = 0LL;
	
	int  i;
	
	if(t == 0)
	{
		for(i = 1; i <= min(seg1,k1); i++)
		{
			if(seg1 - i >= 0)
			{
				ans += solve(seg1-i, seg2, 1-t);
				ans %= mod;
			}
		}
	}
	else
	{
		for(i = 1; i <= min(seg2,k2); i++)
		{
			if(seg2-i >= 0)
			{
				ans += solve(seg1, seg2-i , 1-t) ;		
				ans %= mod;
			}
		}
	}
	return dp[seg1][seg2][t] = ans;
}
int main()
{
	cin >> n1 >> n2 >> k1 >> k2;
	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100; j++)
			for(int k = 0; k < 2; k++)
				dp[i][j][k] = -1LL;
	long long ans = solve(n1,n2,0);
	long long ans2 = solve(n1,n2,1);
	cout << (ans + ans2) % mod << "\n";
}
