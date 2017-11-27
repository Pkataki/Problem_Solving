#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int64 dp[70][70][70];
int used[70][70][70], vis = 1;
string a, b, c;

int64 solve(int i, int j, int k) {
	if (k == c.size()) return 1;

	int64 &ans = dp[i][j][k];
	int &us = used[i][j][k];

	if (us == vis) return ans;
	ans = 0;
	us = vis;

	if (i < a.size())
	{
		for (int w = i; w < a.size(); w++)
		{
			if (a[w] == c[k])
			{
				ans += solve(w + 1, j, k + 1);
			}
		}
	}

	if (j < b.size())
	{
		for (int w = j; w < b.size(); w++)
		{
			if (b[w] == c[k])
			{
				ans += solve(i, w + 1, k + 1);
			}
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		cout << solve(0, 0, 0) << '\n';
		vis++;
	}
	return 0;
}
