#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	long long ans = 0;
	for(long long i = 1; i <= n; i++)
	{
		ans += (1LL << i);
	}
	cout << ans << '\n';
	return 0;
}
