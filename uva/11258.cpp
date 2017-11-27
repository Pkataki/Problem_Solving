#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		string s;
		cin >> s;
		long long dp[205];
		memset(dp,0,sizeof(dp));

		for(int i = s.size() - 1 ; i >= 0; i--)
		{
			long long sum = 0;
			for(int j = i; j < s.size(); j++)
			{
				sum  = sum*10+s[j]-'0';
				if(sum > INT_MAX)
				{
					break;
				}
				dp[i] = max(dp[i],dp[j+1]+sum);
			}
		}
		cout << dp[0] << '\n';
	}
	return 0;
}
