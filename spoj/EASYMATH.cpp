#include <bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b)
{
	return a * (b/__gcd(a,b));
}
long long v[5];
long long solve(long long n)
{
	int tot = (1 << 5);
	long long ans1 = 0;
	for(int mask = 1; mask < tot; mask++)
	{
		long long val = 1;
		int m = 0;
		bool just_one = 0;
		int num_bits = __builtin_popcount(mask);
		for(int i = 0 ; i < 5; i++)
		{
			if(mask & (1 << i) && num_bits != 1)
				val = lcm(val,v[i]);
			else if(mask & (1 << i) && num_bits == 1)
				val = v[i];
		}
		if(num_bits & 1)
			ans1 += n/val;
		else
			ans1 -= n/val;
	}
	return ans1;
}
long long _abs(long long x)
{
	if(x < 0)
		return -1LL*x;
	else
		return x;
}
int main()
{
	long long n,m,a,d;
	int test;
	cin >> test;
	while(test--)
	{
		cin >> n >> m >> a >> d;
		for(long long i = 0; i < 5 ; i++)
		{
			v[i] = a + i*d;
		}		
		cout << _abs((m-n+1) - (solve(m)-solve(n-1))) << '\n';
	}
	return 0;
}
