#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,d;
	cin >> n >> d;
	vector<pair<long long,long long> >v(n);
	for(int i = 0 ; i < n ; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(),v.end());
	
	int r;
	r = 0;
	long long sum = 0;	
	long long ans = 0;

	for(int l = 0 ; l < n ; l++)
	{
		while(r < n && v[r].first < v[l].first + d)
		{
			sum += v[r].second;
			r++;
		}
		ans = max(ans,sum);
		sum -= v[l].second;
	}
	cout << ans << '\n';
	return 0;
}
