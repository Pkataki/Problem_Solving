#include<bits/stdc++.h>
using namespace std;
long long v[100005];
vector<long long>a;
const int MOD = 1e9 + 7;
long long poww(long long n, long long b)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1)
			ans = (ans * n) % MOD;
		n =	(n * n) %  MOD;
		b >>= 1;
		
	}
	return ans;
}
int main()
{
	long long n,x;
	cin >> n >> x;
	long long sum = 0;	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	for(int i = 0; i < n; i++)
	{
		a.push_back(sum - v[i]);
	}
	sort(a.rbegin(),a.rend());
	while(true)
	{
		long long v1 = a[a.size() - 1];
		int cnt = 0;
		while(a[a.size() - 1] == v1 && a.size() > 0)
		{
			cnt++;
			a.pop_back();
		}
		if(cnt % x == 0)
		{
			int aux = cnt/x;
			for(int i = 0; i < aux; i++)
			{
				a.push_back(v1 + 1);
			}
		}
		else
		{
			v1 = min(sum,v1);
			cout << poww(x , v1) << '\n';
			return 0;
		}
	}
	
	return 0;
}
