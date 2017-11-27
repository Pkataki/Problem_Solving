#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,d;
	cin >> n >> m >> d;
	n *= m;
	int v[n];
	int r = -1;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		if(r == -1)
		{
			r = v[i] % d;
		}
		else
		{
			if(r != v[i] % d)
			{
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	sort(v,v+n);
	int target = v[n/2];
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans += abs(v[i]-target)/d;
	}
	cout << ans << '\n';
}
