#include <bits/stdc++.h>

using namespace std;

#define int64 long long

vector< int64 > L;
int64 l,r;
void dfs(int64 x)
{
	if (x >= l) L.push_back(x);
	if (x > r) return ;
	
	dfs(x * 10 + 4);
	dfs(x * 10 + 7);
}

int main()
{
	cin >> l >> r;
	dfs(0);
	sort(L.begin(),L.end());
	int64 c = l, ans = 0;
	while(c <= r)
	{
		int64 lb = *lower_bound(L.begin(), L.end(),c);
		int64 hi = min((int64)r,lb);

		ans += lb * (hi - c + 1);
		c = lb + 1;	
	}
	cout << ans  << '\n';
}
