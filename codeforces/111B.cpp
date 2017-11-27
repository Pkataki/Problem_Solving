#include <bits/stdc++.h>
int last[100005];
using namespace std;
int main()
{
	int q;
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		int ans = 0;
		for(int j = 1; j *j <= x ; j++)
		{
			if(x % j == 0)
			{
				if(last[j] < i - y)
				{
					ans++;
				}
				last[j] = i;
				if(j != x/j)
				{
					if(last[x/j] < i - y)
					{
						ans++;
					}
					last[x/j] = i;
				}
			}
		}
		cout << ans << '\n';
	}
}
