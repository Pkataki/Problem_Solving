#include <bits/stdc++.h>
using namespace std;
long long dp[1000005];
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n,k;
		string s;
		cin >> n >> k;
		cin >> s;
		long long sum = 0;
		dp[0] = 1;
		long long ans = 0;
		for(int i = 0 ; i < n ; i++)
		{
			sum += s[i] - '0';
			if(sum - k>= 0)
				ans += dp[sum-k];
			dp[sum]++;
		}
		cout << ans << '\n';
	}
	return 0;
}
