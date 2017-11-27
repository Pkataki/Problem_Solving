#include<bits/stdc++.h>
using namespace std;
long long phi(long long n)
{
	long long ans = n;
	for(long long i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			ans -= ans / i;
			while(n % i == 0)
				n /= i;
		}
	}
	if(n > 1LL)
		ans -= ans/n;
	return ans;
}
vector<long long> sum(200003);
main()
{
	sum[0] = 0;
	sum[1] = 0;
	for(long long i = 2; i <= 200002; i++)
	{
		long long tmp = phi(i);
		sum[i] = sum[i-1] + tmp;
	}
	long long k;
	while(cin >> k && k)
	{
		
		long long d = (lower_bound(sum.begin(), sum.end(), k) - 1) - sum.begin();
		long long num =  k - sum[d];
		long long i;
		for(i = 1; num; i++)
			if(__gcd(i,d) == 1)
				num--;
		
		cout << i-1 << "/" << d << "\n";
	}
}
