#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int v[n];
	for(int i = 0 ; i < n; i++)
	{
		cin >> v[i];
	}
	int l;
	l = 0;
	int sum = 0;
	int ans  = 0;
	int cont = 0;
	for(int i = 0 ; i < n ; i++)
	{
		sum += v[i];
		cont++;
		while(sum > m)
		{
			sum -= v[l];
			l++;
			cont--;
		}
		ans = max(ans,cont);
	}
	cout << ans << '\n';
	return 0;
}
