#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
bool check(long long x)
{
	long long ans = 0;
	
	for(int i = 1; i <= n ; i++)
	{
		ans += min((long long )((x-1)/i),m);
	}
	return (ans < k);
}
int main()
{
	cin >> n >> m >> k;
	long long lo = 1LL;
	long long hi = n*m+1;
	long long ans = 0;
	while(lo <= hi)
	{
		long long mid = (lo + hi) >> 1LL;
		if(check(mid))
		{
			 ans = mid;
			lo = mid + 1 ;
		}
		else
		{
			 hi = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
