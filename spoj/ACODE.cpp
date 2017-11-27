#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin >> s)
	{
		if(s == "0")
			break;
		int dp[s.size()+3];
		dp[0] = 1;
		dp[1] = 1;
		for(int i = 2; i <= s.size(); i++)
		{
			dp[i] = 0;
			char c1 = s[i-2]-'0', c2 = s[i-1]-'0';
			
			if(c1==1 || (c1==2 && c2<=6)) dp[i] += dp[i-2];
			if(c2!=0) dp[i] += dp[i-1];
			
		}
		cout << dp[s.size()] << '\n';
	}

}
