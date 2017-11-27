#include<bits/stdc++.h>
using namespace std;
long long gcd (long long a, long long b, long long & x, long long & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd (b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
int main()
{
	long long a,b,x,y;
	while(scanf("%lld %lld",&a,&b))
	{
		long long d = gcd(a,b,x,y);
		if(a == b)
		{
			x = 0;
			y = 1;
		}
		cout << x << ' ' << y <<' ' << d << '\n';
 	}
	return 0;
}
