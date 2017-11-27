#include <bits/stdc++.h>
using namespace std;
bool solve(string a, string b)
{
	if(a.size() & 1 || b.size() & 1)
	{
		return a == b;
	}
	if(a == b)
		return true;
	return (solve(a.substr(0,a.size()/2),b.substr(0,b.size()/2))
	&& solve(a.substr(a.size()/2,a.size()),b.substr(b.size()/2,b.size()))
	|| solve(a.substr(a.size()/2,a.size()),b.substr(0,b.size()/2))
	&& solve(a.substr(0,a.size()/2),b.substr(b.size()/2,b.size()))
	);
}
int main()
{
	string a,b;
	cin >> a >> b;
	cout << (solve(a,b) == true? "YES" : "NO") << '\n';
}
