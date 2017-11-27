#include<bits/stdc++.h>
using namespace std;
long long v[100005];
map<long long,bool>mapa;
int main()
{
	int n;
	long long k;
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> v[i];
	}
	sort(v,v+n);
	long long  ans = 0;
	for(int i = 0 ; i < n ; i++)
	{
		if(mapa[v[i]] == 0)
		{
			ans++;
			mapa[v[i]*k] = 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
