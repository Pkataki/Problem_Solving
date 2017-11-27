#include<bits/stdc++.h>
using namespace std;
int last[1000015];
int cnt[1000015];
int main()
{
	int n;
	
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		cnt[a]++;
	}
	
	for(int i = 1; i <= 1000010; i++)
	{
		if(cnt[i])
			last[i] = i;
		else
			last[i] = last[i-1];
	}
	
	int ans = 0;
	
	for(int i = 1; i <= 1000010; i++)
	{
		if(cnt[i])
		{
			for(int j = i; j < 1000010;)
			{
				int f = min(j + i, 1000010) - 1;
				int k = last[f];
				if(k >= i)
				{
					ans = max(ans, k % i);
				}
				j = f + 1;
			}
		}
	}
	
	cout << ans << '\n';

	return 0;
}
