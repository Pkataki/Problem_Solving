#include<bits/stdc++.h>
using namespace std;
int v[200005];
int a[1000005];
int main()
{
	int n,m,k;
	cin >> n >>  m  >> k ;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> v[i];
	}
	sort(v+1,v+n+1);
	int s = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		a[++s] = v[i];
		if(s >= k)
		{
			if(a[s] - a[s - k + 1] < m)
			{
				s--;
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
