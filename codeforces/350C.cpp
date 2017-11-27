#include <bits/stdc++.h>
using namespace std;
pair<int, pair<int,int> > v[100005];
void solve(int x, int y)
{
	if(x > 0)
		cout << "1 " << x << " R\n";
	if(x < 0)
		cout << "1 " << -x << " L\n";
	if(y > 0)
		cout << "1 " << y << " U\n";
	if(y < 0)
		cout << "1 " << -y << " D\n";
}
int main()
{
	int n;
	cin >> n;
	int ans = 0;
	for(int i  = 0 ; i < n ; i++)
	{
		cin >> v[i].second.first >> v[i].second.second;
		v[i].first = abs(v[i].second.first) + abs(v[i].second.second);
		ans += 2 + 2 * (v[i].second.first != 0) + 2 * (v[i].second.second != 0);
	}
	sort(v,v+n);
	cout << ans << '\n';
	for(int i= 0 ; i < n ; i++)
	{
		solve(v[i].second.first,v[i].second.second);
		cout << "2\n";
		solve( -v[i].second.first, -v[i].second.second);
		cout << "3\n";
	}
	return 0;
}
