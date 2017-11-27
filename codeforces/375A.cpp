#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string b = "1689";
	for(int i = 0 ; i < b.size(); i++)
	{
		s.erase(find(s.begin(),s.end(), b[i]));
	}
	if(count(s.begin(),s.end(), '0') == s.size())
	{
		cout << "1869" << s << '\n';
		return 0;
	}
	sort(s.begin(),s.end(),greater<char>());
	do 
	{
		string t = s + b;
		int ans = 0;
		for (int i = 0; i < t.size(); ++i) 
		{
			ans = ans * 10 + t[i] - '0';
			ans %= 7;
		}
		if (ans == 0) 
		{
			cout << t << endl;
			return 0;
		}
	} while (next_permutation(b.begin(), b.end()));

	return 0;
}
