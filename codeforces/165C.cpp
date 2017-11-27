#include<bits/stdc++.h>
using namespace std;
long long dp[1000005];
int main()
{
	int k;
	cin >> k;
	string s;
	cin >> s;
	long long sum = 0LL;
	int n = s.size();
	long long ans = 0;
	
	dp[0] = 1;

	for(int i = 0; i < n; i++)
	{
		if(s[i] == '1') 
			sum++;
		if(sum - k >= 0)
			ans += dp[sum-k];
		dp[sum]++;
	}
	
	cout << ans << '\n';
}
