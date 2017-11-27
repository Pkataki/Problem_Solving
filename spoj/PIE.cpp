#include<bits/stdc++.h>
using namespace std;
int v[10005];
long double pi=3.14159265358979323846264338327950;
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		long double hi = 0.;
		long double lo = 0.;
		int n,m;
		cin >> n >> m;
		for(int i  = 0; i < n ; i++)
		{
			cin >> v[i];
			v[i] = v[i]*v[i];
		}
		hi = 1e9;
		sort(v,v+n);
		for(int j = 0; j < 300; j++)
		{
			long double mid = (lo+hi)/2.0;
			int aux = 0;
			for(int i = n-1 ; i >= 0 && aux <= m ; i--)
			{
				aux += floor(pi*v[i]/mid);
			}
			if(aux > m)
			{
				lo = mid;
			}
			else
				hi = mid;
		}
		cout << fixed << setprecision(4) << lo << '\n';
	}
	return 0;
}
