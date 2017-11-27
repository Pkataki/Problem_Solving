#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int v[n];
	pair<int,int> v1[m];
	int ans[m];

	for(int i = 0 ; i < n ; i++)
		cin >> v[i];
	
	for(int i = 0 ; i < m ; i++)
	{
		ans[i] = 0;
		cin >> v1[i].first;
		v1[i].second = i;
	}
	sort(v,v+n);
	sort(v1,v1+m);
	int r = 0;
	for(int i = 0 ; i < m; i++)
	{
		while(r < n && v1[i].first >= v[r])
		{
			r++;
		}
		ans[v1[i].second] = r;
	}
	for(int i = 0 ; i < m ; i++)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;

}
