#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007ll; 
int main()
{
	int n;
	cin >> n;
	if(n == 1)
	{
		cout << 0 << '\n';
		return 0;
	}
	long long t = 1;
	long long ans = 0;
	long long prev = 0;
	for(int i = 1; i < n; i++)
	{
		t = 3LL * t;
		ans = t - prev;
		if(ans < 0)
			ans += mod;
		t %= mod;
		ans %= mod;
		prev = ans;
	}
	cout << ans << '\n';
}
