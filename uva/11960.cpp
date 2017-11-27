#include <bits/stdc++.h>
using namespace std;
int dp[1000006];
int best[1000006];
int maxn = 1000005;
int main()
{
	ios_base::sync_with_stdio(0);
	for(int i = 2 ; i <= maxn; i++)
	{
		for(int j = i; j <= maxn; j += i)
			dp[j]++;
	}
	best[1] = 1;
	for(int i = 2; i <= maxn; i++)
	{
		if(dp[best[i-1]] > dp[i])
			best[i] = best[i-1];
		else 
			best[i] = i;
	}
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << best[n] << '\n';
	}
}
