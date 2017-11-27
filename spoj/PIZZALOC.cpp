#include<bits/stdc++.h>
using namespace std;
int dist;
bool in_radius(int x1, int y1, int x2, int y2)
{
	int aux1=(x1-x2);
	aux1 *= aux1;
	int aux2 = (y1-y2);
	aux2 *= aux2;
	return ((aux1 + aux2) <= dist);
}
int reach[100];
main()
{
	int k,r;
	cin >> k >> r;
	dist = r*r;
	int m;
	cin >> m;
	vector<pair<int,int> >restaurants(m);
	for(int i = 0; i < m; i++)
		cin >> restaurants[i].first >> restaurants[i].second;
	int n;
	cin >> n;
	vector<pair<int,pair<int,int> > >soli(n);
	for(int i = 0; i < n; i++)
		cin >> soli[i].first >> soli[i].second.first >> soli[i].second.second;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(in_radius(soli[i].first,soli[i].second.first,restaurants[j].first, restaurants[j].second))
				reach[i] |= (1 << j);
		}
	}
	
	int ans = 0;
	for(int mask = 0; mask < (1 << m); mask++)
	{
		if(__builtin_popcount(mask) == k)
		{
			int aux = 0;
			for(int i = 0; i < n; i++)
			{
				if(mask & reach[i])
					aux += soli[i].second.second;
			}
			ans =max(aux,ans);
		}
	}
	cout << ans << '\n';
}
