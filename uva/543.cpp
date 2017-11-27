#include<bits/stdc++.h>
using namespace std;
bitset<1000010>bs;
vector<int>primes;
void sieve()
{
	bs.set();
	bs[0] = bs[1] = 0;
	for(long long i = 2; i <= 1000000; i++)
	{
		if(bs[i])
		{
			for(long long j = i * i; j <= 1000000; j += i)
				bs[j] = 0;
			
			primes.push_back((int)i);
		}
	}
}
main()
{
	sieve();
	int n;
	while(cin >> n && n)
	{
		for(int i = 0; i < primes.size(); i++)
		{
			if(bs[n - primes[i]])
			{
				cout << n << " = " << primes[i] << " + " << n - primes[i] << "\n";
				break;
			}
		}
	}
}
