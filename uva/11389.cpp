#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,d,r;
	while(cin >> n >> d >> r && (n+d+r) != 0)
	{
		int morning[n];
		int evening[n];
		for(int i = 0 ; i < n; i++)
		{
			cin >> morning[i];
		}
		for(int i = 0 ; i < n ; i++)
		{
			cin >> evening[i];
		}
		sort(morning,morning+n);
		sort(evening,evening+n,greater<int>());
		long long ans = 0;
		for(int i = 0 ; i < n ; i++)
		{
			if(morning[i]+evening[i] > d)
			{
				ans += (long long)(morning[i]+evening[i]-d)*r;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
