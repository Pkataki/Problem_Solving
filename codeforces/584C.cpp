#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
long long poww(int b, long long p)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1)
		{
			ans = (ans * p) % MOD;
		}
		p = (p * p) % MOD;
		b >>= 1;
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	long long ans = (poww(3*n,3LL) - poww(n,7) + MOD) % MOD;
	cout << ans << '\n';
	return 0;
}
