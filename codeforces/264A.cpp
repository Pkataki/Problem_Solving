#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int ans[s.size()];
	int l = 0;
	int r = s.size()-1;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'l')
			ans[r--] = i+1;
		else
			ans[l++] = i+1;
	}
	for(int i = 0; i < s.size(); i++)
		cout << ans[i] << '\n';
}
