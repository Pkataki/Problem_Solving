#include<bits/stdc++.h>
using namespace std;
bool isvowel(char c)
{
	char v[] = {'a','e','i','o','u','y'};
	for(int i = 0; i < 6; i++)
	{
		if(c == v[i])
			return 1;
	}
	return 0;
}

int main()
{
	string s;
	cin >> s;
	bool ok = 0;
	for(int i = 0; i < s.size()-1; i++)
	{
		if(isvowel(s[i]) && isvowel(s[i+1]))
			ok = 1;
		else
			ok |= (s[i] == s[i+1]);
	}
	if(!ok)
		cout << "Yes\n";
	else
		cout << "No\n";
}
