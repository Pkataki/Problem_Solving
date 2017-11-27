#include <bits/stdc++.h>
using namespace std;


long long lcm(long long a, long long  b)
{
	return (b/__gcd(a,b))*a;
}
int main()
{
	long long n,k;
	cin >> n >> k;
	long long v[k];
	for(int i = 0; i < k; i++)
	{
		cin >> v[i];
	}
	int tot = (1 << k);
	long long ans = 0;
	for(int mask = 1 ; mask < tot; mask++)
	{
		long long val = 1;
		int m = 0;
		for(int i = 0; i < k; i++)
		{
			if(mask & (1 << i))
			{
				m++;
				val = lcm(val,v[i]);
			}
		}
		if(m & 1)
			ans += n/val;
		else
			ans -= n/val;
	}
	cout << n - ans << '\n';
	return 0;
}
