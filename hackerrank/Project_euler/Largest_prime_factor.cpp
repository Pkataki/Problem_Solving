#include<bits/stdc++.h>
using namespace std;
vector<long long>primes;
bitset<1000005>bs;
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		long long n;
		cin >> n;
		long long big =  0;
		for(long long i = 2; i*i <= n; i++)
		{
			while(n % i == 0)
			{
				n /= i;
				big = i;
			}
		}
		if(n > 1)
		{
			big = max(big,n);
		}
		cout << big << '\n';
	}
	return 0;
}
