#include<bits/stdc++.h>
using namespace std;
long long v[2005];
long long dp[2005];

	int n,k;
bool check(long long val)
{
	dp[0] = 0;
	for(int i = 2; i <= n; i++)
	{
		dp[i] = i-1;
		for(int j = 1; j < i; j++)
		{
			if(abs(v[i] - v[j]) <= val * (i - j))
			{
				dp[i] = min(dp[i], dp[j] + (i-j-1));
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
	//	cout << (dp[i] + n-i) << ' ' << k << endl; 
		if(dp[i] + (n-i) <= k)
			return true;
	}
	return false;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i = 1 ; i <= n ; i++)
		scanf("%lld",&v[i]);
	long long hi = (long long)1e15;
	long long lo = 0;
	long long ans = LLONG_MAX;
	while(lo <= hi)
	{
		long long mid = (lo + hi) / 2LL;
		//cout << mid << endl;
		if(check(mid))
		{
			ans = mid;
			hi = mid-1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}