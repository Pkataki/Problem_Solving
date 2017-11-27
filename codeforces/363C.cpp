#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string ans = "";
	int n = s.size();
	for(int i = 0 ; i < n ; i++)
	{
		int n1 = ans.size();
		bool ok = 1;
		if(n1 >= 2)
			if(ans[n1-1] == ans[n1-2] && ans[n1-1] == s[i])
				ok = 0;
		if(n1 >= 3)
			if(ans[n1-3] == ans[n1-2] && ans[n1-1] == s[i])
				ok = 0;
		if(ok)
			ans+=s[i];
	}
	cout << ans << '\n'; 
	return 0;
}
