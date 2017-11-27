#include <bits/stdc++.h>
using namespace std;
int house[1000005];
int n,m;
bool check(int dist)
{
	int last = house[0] + dist;
	int used = 1;
	for(int i = 0 ; i < m && used <= n; i++)
	{
		if(abs(last - house[i]) > dist)
		{
			used++;
			last = house[i] + dist;
		}
	}
	return used <= n;
}
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		cin >> n >> m;
		for(int i = 0 ; i < m; i++)
		{
			cin >> house[i];
			house[i] *= 10;
		}
		sort(house,house+m);
		int hi = house[m-1] - house[0];
		int lo = 0;
		int ans = 0;
		while(lo <= hi)
		{
			int dist = (lo+hi) >> 1;
			if(check(dist))
			{
				ans = dist;
				hi = dist - 1;
			}
			else
				lo = dist + 1;
		}
		cout << ans/10 << "." << ans % 10 << '\n';
	}
}
