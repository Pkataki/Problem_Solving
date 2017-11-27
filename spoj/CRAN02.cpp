#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	while(test--)
	{
		map<long long,long long>mapa;
		int n;
		cin >> n;
		int v[n];
		cin >> v[0];
		long long sum = v[0];
		mapa[sum]++;
		for(int i = 1 ; i < n ; i++)
		{
			cin >> v[i];
			sum += v[i];
			mapa[sum]++;
		}
		long long ans = 0;
		for(map<long long, long long>::iterator it = mapa.begin(); it != mapa.end(); it++)
		{
			ans += (it->second * (it->second-1LL))/2LL;
			ans += (it->first == 0LL ? it->second : 0LL);
		}
		cout << ans << '\n';
	}
	return 0;
}
