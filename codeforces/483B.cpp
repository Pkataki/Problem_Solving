#include<bits/stdc++.h>
using namespace std;
long long cnt1, cnt2, x, y;
long long lcm;
bool check(long long val)
{
	long long nx = val - val/x;
	long long ny = val - val/y;
	long long nxy = val - val/lcm;

	return (cnt1 <= nx && cnt2 <= ny && (cnt1+cnt2 <= nxy));
}
int main()
{
	cin >> cnt1 >> cnt2 >> x >> y;
	long long aux = __gcd(x,y);
	lcm = x/aux*y;
	long long l = 0;
	long long r = 1e18;
	while(l < r)
	{
		long long mid = (l + r ) >> 1LL;
		if(check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << "\n";
}
