#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
	ios_base::sync_with_stdio(0);
	int n;
	ll k;
	int gc;
	cin >> n >> k;
	cin >> gc;
	for(int i = 0; i < n-1; i++)
	{
		int a;
		cin >> a;
		gc = __gcd(gc,a);
	}
	ll lo = 0;	
	ll hi = k;	
	while(lo <= hi)
	{
		ll mid = (lo + hi) >> 1LL;
		if(mid % gc == 0)
			lo = mid + 1;
		else
			hi = mid-1;
	}
	cout << lo-1 << "\n";
}
