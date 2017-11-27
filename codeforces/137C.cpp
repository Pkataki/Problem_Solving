#include <bits/stdc++.h>
using namespace std;
pair<int,int>v[100005];
int main()
{
	int n;
	cin >> n;
	
	for(int i = 0 ; i < n ; i++)
		cin >> v[i].first >> v[i].second;
	
	sort(v,v+n);
	int ans = 0;
	int ma = v[0].second;
	for(int i = 1 ; i < n ; i++)
	{
		if(v[i].second > ma)
		{
			ma = v[i].second;
		}
		else
		 ans++;
	}
	cout << ans << '\n';
	return 0;
}
