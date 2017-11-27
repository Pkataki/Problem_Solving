#include<bits/stdc++.h>
using namespace std;
long long table[100010][18];
main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int>v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int k = log2(n);
	k += 1;
	for(int i = 0; i < n; i++)
	{
		table[i][0] = v[i];
	}
	for(int j = 1; j <= k; j++)
	{
		for(int i = 0 ; i + (1 << j) <= n ; i++)
		{
			table[i][j] = min(table[i][j - 1],table[i + (1 << (j - 1))][j - 1]);
		}
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int l,r;
		cin >> l >> r;
		long long ans = (1LL << 60);
		for(int j = k; j>= 0; j--)
		{
			if(l + (1 << j) - 1 <= r)
			{
				ans = min(ans,table[l][j]);
				l += 1 << j;
			}
			
		}
		cout << ans << "\n";
	}

}
