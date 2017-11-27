#include <bits/stdc++.h>
using namespace std;
string v[105];
const long long MOD = 1000000007;
int main()
{
	long long n,m;
	cin >> n >> m;
	set<char>s;
	long long ans = 1LL;
	for(int i = 0; i < n ; i++)
	{
		cin >> v[i];
	}
	for(int i = 0; i < m; i++)
	{
		s.clear();
		for(int j = 0; j < n; j++)
		{
			s.insert(v[j][i]);
		}
		ans  = (ans * (long long)(s.size())) %MOD;
	}
	cout << ans << '\n';
	return 0;
}
