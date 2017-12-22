#include<bits/stdc++.h>
using namespace std;
long long v[200005];
bool vis[200005];
set<long long>sq;
vector<pair<long long,long long> >a;
int main()
{
	int n;
	for(long long i = 0; i * i <= 2000000000; i++)
		sq.insert(i*i);

	cin >> n;

	for(int i = 0; i < n ; i++)
		cin >> v[i];

	for(int i = 0; i < n ; i++)
	{
		auto val = sq.lower_bound(v[i]);
		if(val == sq.end())
		{
			val--;
			a.push_back({abs(v[i] - *val),v[i]});
		}
		else
		{
			if(*val == v[i])
				a.push_back({0,v[i]});
			else
			{
				long long aux = abs(v[i] - *val);
			
				if(val != sq.begin())
					--val;
				aux = min(aux,abs(v[i] - *val));

				a.push_back({aux,v[i]});
				
			}
		}
	}
	sort(a.begin(),a.end());

	long long ans = 0;
	int lim = n/2;
	for(int i = 0; i < n ; i++)
	{
		if(i < lim)
			ans += a[i].first;
		else
		{
			if(a[i].second == 0)
				ans += 2;
			else if(((int)sqrt(a[i].second) * (int)sqrt(a[i].second)) == a[i].second)
				ans += 1;
			
		}
	}
	cout << ans << '\n';
	
	return 0;
}
