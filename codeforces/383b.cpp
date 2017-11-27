#include<bits/stdc++.h>
using namespace std;
map<int,int>mapa;
main()
{
	ios_base::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	vector<int>odd;
	vector<int>even;
	for(int i = 0;i < n; i++)
	{
		int a;
		cin >> a;
		if(!mapa.count(a))
		{
			if(a & 1)
				odd.push_back(a);
			else
				even.push_back(a);
		}
		mapa[a]++;
	}
	int ans = 0;
	if(m & 1)
	{
		for(int i = 0; i < odd.size(); i++)
		{
			for(int j = 0; j < even.size(); j++)
			{
				if((odd[i] ^ even[j]) == m)
					ans += mapa[odd[i]] * mapa[even[j]];
			}
		}
	}
	else
	{
		for(int i = 0; i < odd.size(); i++)
		{
			for(int j = i; j < odd.size(); j++)
			{
				if((odd[i] ^ odd[j]) == m)
					ans += mapa[odd[i]] * mapa[odd[j]];
			}
		}
		for(int i = 0; i < even.size(); i++)
		{
			for(int j = i; j < even.size(); j++)
			{
				if((even[i] ^ even[j]) == m)
					ans += mapa[even[i]] * mapa[even[j]];
			}
		}
	}
	cout << ans <<'\n';	
}
