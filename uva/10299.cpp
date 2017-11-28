#include<bits/stdc++.h>
using namespace std;
long long phi(long long n)
{
	if(n == 1)
		return 0LL;
	long long ans = n;
	for(long long i = 2 ; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			while(n % i == 0)
				n /= i;
			ans -= ans/i;
		}
	}
	if(n > 1)
		ans -= ans/n;
	return ans;
}
int main()
{
	long long n;
	while(scanf("%lld",&n) == 1 && n != 0)
	{
		
		printf("%lld\n",phi(n));
	}
	return 0;
}
