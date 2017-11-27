#include<bits/stdc++.h>
using namespace std;
int n,m,d;
int v[10005];
long long f(long long val)
{
	long long sum = 0;
	for(int i = 0 ; i < n; i++)
	{
		sum += llabs(v[i]-val)/d;
	}
	return sum;
}
int main()
{
	cin >> n >> m >> d;
	n = n*m;
	bool ok = 0;
	int r = -1;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		if(r == -1)
		{
			r = v[i] % d;
		}
		else
		{
			if(r != v[i] % d)
			{
				cout << -1 << '\n';
				return 0;
			}
		}
	}	
	long long lo = 0;
	long long hi = 100000;
	for(int i = 0 ; i < 300; i++)
	{
		long long mid1 = (2*lo+hi)/3;
		long long mid2 = (2*hi+lo)/3;
		if(f(mid1) < f(mid2))
			hi = mid2;
		else
			lo = mid1;
	}
	long long ans = LLONG_MAX;
	for(long long i = lo; i  <= hi; i++)
	{
		if(i%d == r)
		ans =min(ans,f(i));
	}
	cout << ans << '\n';
	return 0;
}
