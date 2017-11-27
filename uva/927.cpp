#include<bits/stdc++.h>
using namespace std;
#define uint64 unsigned long long
uint64 exp(uint64 b, uint64 n)
{
	uint64 ans = 1;
	while(b)
	{
		if(b & 1ULL)
			ans *= n;
		n *= n;
		b >>= 1ULL;
	}
	return ans;
}
main()
{
	int test;
	cin >> test;
	while(test--)
	{
		uint64 n;
		cin >> n;
		n++;
		vector<uint64>c(n);
		for(int i = 0; i < n; i++)
			cin >> c[i];
		uint64 k,d;
		cin >> d >> k;
		uint64 sum = 0;
		for(uint64 i = 0; i <= k; i++)
		{
			sum += i*d;
			if(sum >= k)
			{
				uint64 ans = 0;
				for(int j = 0; j < n; j++)
				{
					ans += c[j] * exp(j,i);
				}
				cout << ans << '\n';
				break;
			}
		}
	}
}
