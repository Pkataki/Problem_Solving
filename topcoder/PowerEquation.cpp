#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 +7;
long long gcd(long long a,long long b){
    return a?gcd(b%a,a):b;
}
class PowerEquation
{
	public : int count(int n1)
	{
		long long n =  n1;
		long long ans = n*(n*2LL-1LL)%MOD;
		set<long long>s;
		for(long long p = 2; p *p <= n; p++)
		{
			if(s.count(p))
				continue;
			long long k = 0;
			long long tmp = p;
			while(tmp <= n)
			{
				s.insert(tmp);
				k++;
				tmp *= p;
			}
			for(long long x = 1; x <= k; x++)
			{
				for(long long y = x+1; y <=k; y++)
				{
					long long g = gcd(x,y);
					long long y1 = y / g;
					ans = (ans + 2LL*(n / y1)) % MOD;
				}
			}
		}
	
		return ans;
	}
};
