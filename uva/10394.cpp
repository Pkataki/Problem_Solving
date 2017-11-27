#include<bits/stdc++.h>
using namespace std;
bitset<20000010>bs;
int v[100005];

void sieve()
{
	bs.set();
	
	bs[0] = bs[1] = 0;
	

	for(long long i = 2; i * i <= 20000000; i++)
	{
		if(bs[i])
		{
			for(long long j = i * i; j <= 20000000; j += i )
			{
				bs[j] = 0;
			}			
		}
	}
	int t = 1;
	for(int i = 0; i <= 20000000; i++)
	{
		if(t > 100000)
			break;
		if(bs[i] && bs[i+2])
		{
			v[t] = i;
			t++;
		}
	}
}
main()
{
	sieve();
	int n;
	while(cin >> n)
	{
		cout << "(" << v[n] << ", " << v[n]+2 << ")\n";
	}
}
