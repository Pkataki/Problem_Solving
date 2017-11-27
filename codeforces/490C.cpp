#include <bits/stdc++.h>
using namespace std;
int v[1000006];
int v1[1000006];
int main()
{
	string s;
	cin >> s;
	int a,b;
	cin >> a >> b;
	int p = 1;
	int t = 0;
	for(int i = 0; i < s.size(); i++)
	{
		t = ((t * 10)%a + (s[i] - '0')) % a;
		v[i] = t;
	}
	t = 0;
	for(int i = s.size() - 1; i >= 0 ; i--)
	{
		t = (t + ((s[i] - '0') * p ) %b ) %b;
		v1[i] = t;
		p *= 10;
		p %= b;
	}
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i] != '0' && v[i-1] == 0 && v1[i] == 0)
		{
			cout << "YES\n";
			cout << s.substr(0,i) << '\n';
			cout << s.substr(i) << '\n';
			return 0;
		}
	}
	cout << "NO\n";

	return 0;
}
