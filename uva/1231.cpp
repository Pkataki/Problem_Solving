#include <bits/stdc++.h>
using namespace std;
int dp[2005];
int acorn[2005][2005];
int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	while(test--)
	{
		int t,h,f;
		cin >> t >> h >> f;
		memset(dp,0,sizeof(dp));
		memset(acorn,0,sizeof(acorn));
        
        
        for (int i = 0; i < t; i++)
        {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                int loc;
                cin >> loc;
                acorn[i][loc]++;
            }
        }
	
		for (int i = h; i >= 0; i--)
		{
            for (int j = 0; j < t; j++)
            {
                acorn[j][i] += max(acorn[j][i + 1], ((f + i) <= h) ? dp[i + f] : 0);
                dp[i] = max(dp[i], acorn[j][i]);
            }
        }
        printf("%d\n", dp[0]);

	}
}
