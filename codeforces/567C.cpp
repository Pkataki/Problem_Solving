#include<bits/stdc++.h>
using namespace std;
long long v[200005];
int main()
{
	int n,k;
	cin >>n >> k;
	map<long long,long long>r,l;
	for(int i = 0 ; i < n ; i++)
	{
		
		cin >> v[i];
		r[v[i]]++;
	}
	long long ans = 0;
	for(int i = 0 ; i < n ; i++)
	{
		if(v[i] % k == 0)
		{
			r[v[i]]--;
			ans += l[v[i]/k]*r[v[i]*k];
			l[v[i]]++;
		}
		else
		{
			r[v[i]]--;
			l[v[i]]++;
		
		}
	}
	cout << ans << '\n';
	return 0;
}
