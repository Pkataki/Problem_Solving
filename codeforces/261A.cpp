#include<bits/stdc++.h>
using namespace std;
int v[100005];
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int a,q = INT_MAX;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		q = min(q,a);
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
		cin >> v[i];
	sort(v,v+m,greater<int>());
	
	int ans = 0;
	for(int i = 0; i < m; i++)
	{
		if (i % (q+2) < q)
			ans += v[i];
	}
	cout << ans << '\n';
	return 0;
}
