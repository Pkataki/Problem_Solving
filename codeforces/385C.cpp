#include <bits/stdc++.h>
using namespace std;
vector<long long>primes;
bitset<10000005>bs;
void sieve()
{
	bs[0] = 1;
	bs[0] = 1;
	for(long long i = 2 ; i * i  <= 10000000; i++)
	{
		if(!bs[i])
		{
			primes.push_back(i);
			for(long long j = i * i ; j <= 10000000; j += i)
				bs[j] = 1;
		}
	}
}
int occ[10000005];
int cont[10000005];
void preprocess()
{
	for(int i = 2; i <= 10000000; i++)
	{
		cont[i] = cont[i-1];
		if(!bs[i])
		{
			for(int j = i; j <= 10000000; j += i)
				cont[i] += occ[j];
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	sieve();
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++)
	{
		int a;
		cin >> a;
		occ[a]++;
	}
	int q;
	preprocess();
	cin >> q;
	while(q--)
	{
		int x;
		int y;
		cin >> x >> y;
		cout << cont[min(10000000,y)] - cont[min(10000000,x-1)] << '\n';
	}
}
