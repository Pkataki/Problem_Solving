#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	if(s.find("AB") == string::npos || s.find("BA") == string :: npos)
		cout << "NO\n";
	else
	{
		int i = s.find("AB");
		if(s.find("BA", i+2) != string :: npos)
		{
			cout << "YES\n";
			return 0;
		}
		
		i = s.find("BA");
		if(s.find("AB", i+2) != string :: npos)
		{
			cout << "YES\n";
			return 0;
		}
		cout << "NO\n";
	}
	return 0;
}
