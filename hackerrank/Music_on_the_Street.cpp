#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin >> n;
	vector<pair<ll,ll> >intervals;
	vector<ll>quantidade;
	ll aux;
	cin >> aux;
	for(int i ; i < n - 1; i++)
	{
		ll at;
		intervals.push_back(make_pair(aux,at));
		aux = at;
	}
	ll h1,h2,m;
	cin >> m >> h1 >> h2;
	for(int i = 0; i < intervals.size(); i++)
	{
		ll tam = intervals[i].second - intervals[i].first;
		if(h1 < tam)
			
		if(m >= min(tam,h2))
		{
			m -= min(tam,h2);
			quantidade.push_back(min(tam,h2));
		}
		else
		{
			cout << intervals[0].first << "\n";
//			cout << "primeiro\n";
			return 0;
		}
//		cout << "m: " << m << " **\n";
	}
//	cout << "m: " << m << " **\n";
	if(m)
	{
		if(m >= h1 && m <= h2)
		{
			cout << intervals[0].first - m << "\n";
//			cout << "segundo\n"; 
		}
		else if(m > h2)
		{
			int aux = m - h2;
			cout << intervals[0].first - aux << "\n";
//			cout << "terceiro\n";
		}
		else if(m < h1)
		{
			int it = quantidade.size();
			it--;
			while(m < h1)
			{
				m += quantidade[it];
				it--;
			}
			cout << intervals[0].first - m << "\n";
//			cout << "quarto\n";
		}
	}
	else
		cout << intervals[0].first << "\n";
	return 0;
}
