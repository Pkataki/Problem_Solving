#include<bits/stdc++.h>
using namespace std;
string flip(string s)
{
	string t = "";
	for(int i = 0; i < s.size(); i++)
	{
		t += (s[i] == '1'? '0' : '1');
	}
	return t;
}
int main()
{
	string s = "01";
	while(s.size() <= 1000)
	{
		s = s + flip(s);
	}
	int q;
	cin >> q;
	while(q--)
	{
		int a;
		cin >> a;
		cout << s[a] << '\n';
	}
}
