#include<bits/stdc++.h>
using namespace std;
int dp[30][100055];
int v[100055];
int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	for(int t = 1; t <= test; t++)
	{
		int n,q;
		cin >> n >> q;
		for(int i = 0 ; i < n ; i++)
			cin >> v[i];
		
		for(int i = 0 ; i < n ; i++)
			dp[0][i] = v[i];
		
		for(int i = 1; (1 << i ) <= n; i++)
		{
			for(int j = 0; j + (1 << i) <= n ; j++)
			{
				dp[i][j] = min(dp[i-1][j],dp[i-1][j + (1 << (i-1))]);
			}
		}
		cout << "Scenario #" <<t << ":\n";
		
		while(q--)
		{
			int l,r;
			cin >> l >> r;
			l--;
			r--;
			int p = 31 - __builtin_clz(r-l+1);
			cout << min(dp[p][l],dp[p][r-(1 << p)+1]) << '\n';
		}
	}
	return 0;
}
