#include<bits/stdc++.h>
using namespace std;
int cnt[100005];
long long dp[100005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		cnt[a]++;
	}
	dp[0] = 0;
	dp[1] = cnt[1];
	for(int i = 2; i <= 100005; i++)
	{
		dp[i] = max(dp[i-1], dp[i-2] + cnt[i]*(long long)i);	
	}
	cout << dp[100005] << '\n';
	return 0;
}
