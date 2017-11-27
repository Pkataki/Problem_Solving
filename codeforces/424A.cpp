#include<bits/stdc++.h>
using namespace std;
long long pre[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	for(int i = 1 ; i <= 1000000; i++)
	{
		pre[i] = pre[i-1] ^ i;
	}
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n ; i++)
	{
		int a;
		cin >> a;
		if((n/i) & 1)
			a ^= pre[i-1];
		a ^= pre[n%i];
		ans ^= a;
	}
	cout << ans << '\n';
	return 0;
}
