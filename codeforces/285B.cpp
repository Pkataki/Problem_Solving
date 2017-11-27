#include <bits/stdc++.h>
using namespace std;
int p[100005];
int main()
{
	int n,s,t;
	cin >> n >> s >> t;
	for(int i = 1; i <= n ; i++)
		cin >> p[i];
	int at = s;
	int last = -1;
	int ans = 0;
	bool ok = 0;
	while(1)
	{
		last = at;
		at = p[at];
		if(at == t)
		{
			ok = 1;
			break;
		}
		if(at == -1)
		{
			break;
		}
		ans++;
		p[last] = -1;
	}
	if(ok)
	{
		if(s == t)
			cout << 0 << '\n';
		else
			cout << ans+1 << '\n';
	}
	else
		cout << "-1\n";
	return 0;
}

