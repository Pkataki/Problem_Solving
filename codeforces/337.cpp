#include <bits/stdc++.h>
using namespace std;

long long power(long long x, long long y, long long p)
{
        if (y == 0)
                return (1 % p);

        if (y == 1)
                return (x % p);

        long long t = power(x, y/2, p);
        t = (t * t) % p;

        if (y % 2)
                t = (t * x) % p;

        return t;
}

int main ()
{
	long long n, m, k;
	cin >> n;
	cin >> m;
	cin >> k;

	long long x = n / k;
	long long y = n % k;

	long long t = max(0LL, (m - y - ((k - 1) * x)));
	long long mod = 1000000009LL;
	long long p = power(2LL, t, mod);
	long long score = 2LL * (p + mod - 1) * k + m - (t * k);
	score %= mod;
	cout << score << endl;
	return 0;
}
