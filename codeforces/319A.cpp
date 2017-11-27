#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long p[1005];
int main()
{
	string s;
	cin >> s;
	long long ans = 0;
	p[0] = 1;
	for(int i = 1; i <= 1000; i++)
	{
		p[i] = (2 * p[i-1]) % MOD;
	}
	reverse(s.begin(),s.end());
	int n = s.size();
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '1')
		{
			ans = (ans +  ((p[i] * p[i]) % MOD ) * p[n-i-1] %MOD ) % MOD;
		}
	}
	cout << ans << '\n';
	return 0;
}
