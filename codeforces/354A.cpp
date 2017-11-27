#include <bits/stdc++.h>
using namespace std;
long long v[100005];
int main()
{
	long long n,l,r,ql,qr;
	cin >> n >> l >>r >>ql >> qr;
	long long sum = 0;
	for(int i= 0; i < n ; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	long long ans = LLONG_MAX;
	long long r1;
	long long l1 = 0;
	for(int i = 0; i <= n ; i++)
	{
		if(i != 0)
			l1 += v[i-1];
		r1 = sum - l1;
		long long t = l1 * l + r1 * r;
		int j = n-i;
		if(i > j)
			t += (i - j - 1) * ql;
		if(i < j)
			t += (j - i - 1) * qr;
		ans = min(ans,t);
	}
	cout << ans << '\n';
	return 0;
}
