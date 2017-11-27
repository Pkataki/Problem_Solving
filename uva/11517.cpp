#include <bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int val;
		cin >> val;
		int n;
		cin >> n;
		int coins[n];
		for(int i = 0 ; i < n ; i++)
		{
			cin >> coins[i];
		}
		int dp[10005];
		for(int i = 0; i <= 10000; i++)
			dp[i] = (1 << 30);
		dp[0] = 0;
		for(int i = 0 ; i < n ; i++)
		{
			for(int w = 10000 ; w >= coins[i]; w--)
			{
				dp[w] = min(dp[w], dp[w - coins[i]] + 1);
			}
		}
		for(int i = 0; i <= 10000 ; i++)
		{
			if(dp[i] != (1 << 30) && i >= val)
			{
				cout << i << ' ' << dp[i] << '\n';
				break;
			}
		}
		
	}
	return 0;
}
