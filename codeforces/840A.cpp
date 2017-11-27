#include<bits/stdc++.h>
using namespace std;
pair<int,int>v[200005];
int a[200005];
int ans[200005];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n ; i++)
	{
		cin >> a[i];
	}
	sort(a,a+n,greater<int>());
	for(int i = 0 ; i < n ; i++)
	{
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v,v+n);
	for(int i = 0 ; i < n ; i++)
	{
		ans[v[i].second] = a[i];
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
