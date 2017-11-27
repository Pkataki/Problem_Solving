#include <bits/stdc++.h>
using namespace std;
int v[1005];
int n,m;
bool test(int capacity)
{
	
	int used = 1;
	int aux = capacity;
	for(int i = 0 ; i < n; i++)
	{
		if(v[i] > capacity)
			return false;
		if(v[i] > aux)
		{
			if(used == m)
				return false;
			used++;
			aux = capacity;
		}
		aux -= v[i];
	}
	return true;
}
int main()
{
	while(cin >> n >> m)
	{
		for(int i = 0; i < n ; i++)
			cin >> v[i];
		int lo = 1;
		int hi = 1000000000;
		int ans = INT_MAX;
		while(lo <= hi)
		{
			int mid = (lo + hi) >> 1;
			if(test(mid))
			{
				ans = mid;
				hi = mid-1;
			}
			else
			 lo = mid+1;
		}
		cout << ans << '\n';
	}
	
	return 0;
}
