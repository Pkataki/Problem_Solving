#include<bits/stdc++.h>
using namespace std;
pair<long long,long long>v[10005];
int n;
long long f(long long height)
{
	long long sum = 0;
	for(int i = 0 ; i < n ; i++)
	{
		sum += abs(v[i].first-height)*v[i].second;	
	}
	return sum;
}
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		cin >> n;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> v[i].first;
		}
		for(int i = 0 ; i < n ; i++)
			cin >> v[i].second;
		long long lo = 0;
		long long hi = 10000;
		for(int i = 0; i < 300; i++)
		{
			long long mid1 = (2*lo+hi)/3;
			long long mid2 = (2*hi+lo)/3;
			if(f(mid1) < f(mid2))
			{
				hi = mid2;
			}
			else
				lo = mid1;
		}
		long long ans = INT_MAX;
		for(long long i = lo; i <= hi; i++)
			ans = min(ans,f(i));
		cout << ans << '\n';
	}
	return 0;
}
