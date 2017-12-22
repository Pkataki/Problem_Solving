#include<bits/stdc++.h>
using namespace std;
vector<int>v[2];
int main()
{
	int n;
	cin >> n;
	bool ok = 0;
	int s[2] = {0};
	int a = 0;
	if(n == 1)
	{
		cout << 1 << '\n' << 1 << ' ' << 1 << '\n';
		return 0;
	}
	if(n & 1)
		n--, a = 1;
	for(int i = 1; i <= n ; i++)
	{
		v[ok].push_back(i);
		s[ok] += i;
		if(i & 1)
			ok ^= 1;
	}
	if(a && s[0] <= s[1])
	{
		s[0] += n+1;
		v[0].push_back(n+1);
	}
	else if(a && s[1] < s[0])
	{
		s[1] += n+1;
		v[1].push_back(n+1);
	}
	cout << abs(s[0] - s[1]) << '\n';
	cout << v[0].size() << ' ';
	for(int i = 0; i < v[0].size(); i++)
	{
		cout << v[0][i] << ' ';
	}
	cout << '\n';
	return 0;
}
