#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll x, a,b;
		cin >> a >> b >> x;
		ll target = (long long)pow(a,b);
		ll lo = 1;
		ll hi = (ll)1e9;
		ll ans = 0;
		while(lo <= hi)
		{
			ll mid = (lo + hi ) >> 1LL;
			if(x * mid <= target)
			{
				lo = mid+1 ;
				ans = mid;
			}
			else
				hi = mid-1;
		}
		if(abs(target - x*ans) < abs(target - x*(ans+1)))
			cout << x*ans;
		else
			cout << x*(ans+1LL);
		cout << '\n';
	}
}
