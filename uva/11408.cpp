#include <bits/stdc++.h>
using namespace std;
bitset<5000005>primes;
int dp[5000005];
int ans[5000005];
void sieve()
{
	primes.set();
	primes[0] = primes[1] = 0;
	for(int i = 2; i < 5000005; i++)
	{
		if(primes[i])
		{
			dp[i] = i;
		
			for(int j = i+i; j < 5000005; j += i)
			{
				dp[j] += i;
				primes[j] = 0;
			}
		}
	}
	for(int i = 2; i < 5000005; i++)
	{
		ans[i] = ans[i-1];
		if(primes[dp[i]])
			ans[i] += 1;	
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int l,r;
	sieve();
	while(cin >> l && l)
	{
		cin >> r;
		cout << ans[r] - ans[l-1] << '\n';
	}
}
