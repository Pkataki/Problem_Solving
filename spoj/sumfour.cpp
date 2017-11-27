#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int>mapa;
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n],b[n],c[n],d[n];
	mapa.reserve(16000000);
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for(int i = 0; i < n ; i++)
		for(int j  = 0 ; j < n ; j++)
			mapa[c[i] + d[j]]++;
	
	int ans = 0;
	for(int i = 0; i < n ; i++)
	{
		for(int j  = 0 ; j < n ; j++)
		{
			int aux = -(a[i] + b[j]);
			if(mapa.find(aux) != mapa.end())
				ans += mapa[aux];
		}
	}
	cout << ans << '\n';
	return 0;
}
