#include<bits/stdc++.h>
using namespace std;
int dp[70][1 << 17];
class Xscoregame
{
	public : int getscore(vector<int> A)
	{
		n = A.size();
		int ans = 0;
		dp[0][0] = 0;
		for(int mask = 0; mask < (1 << n); mask++)
		{
			for(int i = 0; i < n ; i++)
			{
				if(mask & (1 << i))
					continue;
				int mask1 = mask | (1 << i);
				for(int mod = 0; mod <= 64; mod++)
				{
					int val = dp[mask][mod];
					val += val ^ A[i];
					int m1 = val % 64;
					dp[mask1][m1] = max(dp[mask1][m1], val);
				}
			}
		}
		int ans = 0;
		for(int i = 0; i <= 64; i++)
			ans = max(ans,dp[(1 << n)-1][i]);
		return ans;
	}
};