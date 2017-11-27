#include<bits/stdc++.h>
using namespace std;
int v[100005];
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n,c;
		cin >> n >> c;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> v[i];
		}
		sort(v,v+n);
		int lo = 0;
		int hi = v[n-1];
		int ans = 0;
		while(lo < hi)
		{
			int mid = (lo+hi) >> 1;
			int cont = 1;
			int ok = 0;
			int last = v[0];
			for(int i = 1; i < n ; i++)
			{
				if(v[i] -last >= mid)
				{
					last = v[i];
					cont++;
				}
				if(cont == c)
				{
					ok = 1;
					break;
				}
			}
			if(ok)
			{
				ans = max(ans,mid);
				lo = mid+1;
			}
			else
				hi = mid;
		}
		cout << ans << '\n';
	}
	return 0;
}
