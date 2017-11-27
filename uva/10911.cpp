#include <bits/stdc++.h>
using namespace std;
double dp[(1 << 16) + 1];
int x[50];
int y[50];
double dist(int i ,int j)
{
	return (sqrt(abs(x[i] - x[j])*abs(x[i] - x[j]) + abs(y[i] - y[j]) *  abs(y[i] - y[j])));
}
int n;
double val;
double solve(int mask)
{
	if(__builtin_popcount(mask) == n)
		return 0;
	if(dp[mask] != val)
		return dp[mask];
	double ans = 1e9;
	dp[mask] = ans;
	int p;
	for(int i = 0; i < n; i++)
	{
		if(mask & (1 << i))
			continue;
		p = i;
		break;
	}
	for(int p2 = p + 1 ; p2 < n; p2++)
	{
		if(mask & (1 << p2))
			continue;
		ans = min(ans, solve(mask | (1 << p) | (1 << p2)) + dist(p,p2));
	}
	return dp[mask] = ans;
}
int main()
{
	ios::sync_with_stdio(0);
	string s;
	int caso = 1;
	while(cin >> n && n)
	{
		memset(dp,0,sizeof(dp));
		val = dp[0];
		n *= 2;
		for(int i = 0 ; i < n; i++)
		{
			cin >> s >> x[i] >> y[i];
		}
		cout << "Case " << caso++ << ": " << fixed << setprecision(2) << solve(0) << '\n';
	}
}
