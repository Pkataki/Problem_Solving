#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long k,b,n,t;
	cin >> k >> b >> n >> t;
	int steps = n;
	long long x = 1;
	while(k * x + b <= t)
	{
		x = k * x + b;
		steps--;
	}
	cout << max(0,steps) << '\n';
	return 0;
}
