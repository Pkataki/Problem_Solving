#include<bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b)
{
	return (max(a,b)/__gcd(a,b)) * min(a,b);
}

int main()
{
	long long n;
	cin >> n;
	long long ans1 = 1LL;
	long long ans2 = 1LL;
	for(long long i = 1; i <= 3; i++)
	{
		ans2 = lcm(ans2,max(1LL,n-i));
	}
	ans1 = lcm(n,n-1LL);
	ans1 = max(lcm(ans1,n-2LL),lcm(ans1,n-3LL));
	cout << max(ans1,ans2) << '\n';
	return 0;
}
