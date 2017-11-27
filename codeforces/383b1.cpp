#include<bits/stdc++.h>
using namespace std;
map<int,int>mapa;
main()
{
	int n,m;
	cin >> n >> m;
	vector<int>v(n);
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		mapa[a]++;
		v[i] = a;
	}
	int ans =0;
	for(int i = 0; i < n; i++)
	{
		int aux = v[i] ^ m;
		if(mapa[aux] != 0)
			ans++;
	}
	cout << ans/2 << '\n';
}
