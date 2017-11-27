#include<bits/stdc++.h>
using namespace std;
long long v[1000005];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
		cin >> v[i];
	long long l = 0;
	long long r = LLONG_MAX;
	long long ans ;
	while(l < r)
	{
		long long mid = (l+r)>>1;
		long long aux = 0;
		for(int i = 0 ; i < n; i++)
		{
			if(v[i] > mid)
				aux += v[i]-mid;
		}
		if(aux < m)
		{
			r = mid;
		}
		else
		{
			ans = max(ans,mid);
			l = mid+1;
		}
	}
	cout << ans << '\n';
	return 0;
}
