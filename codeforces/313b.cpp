#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int dp[s.size()];
	int s_size = s.size();
	dp[0] = 0;
	for(int i = 1; i < s_size; i++)
	{
		dp[i] = dp[i-1] + (s[i] == s[i-1]);	
	}
	int q;
	cin >> q;
	while(q--)
	{
		int l,r;
		cin >> l >> r;

		cout << dp[r-1] - dp[l-1] << '\n';
	}

}
