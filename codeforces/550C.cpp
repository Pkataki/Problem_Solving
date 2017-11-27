#include<bits/stdc++.h>
using namespace std;
string s;
bool dp[105][1005];
void solve(int pos, int sum)
{
	if(((sum % 8) == 0 )&& (sum != 0))
	{
		cout <<"YES\n" << sum << '\n';
		exit(0);
	}
	if(pos == s.size())
		return;
	if(dp[pos][sum] != 0)
		return;
	solve(pos+1,sum);
	solve(pos+1,((sum*10) + (s[pos] - '0')) % 1000);
	dp[pos][sum] = 1;
}
int main()
{
	cin >> s;
	if(s.find("8") != string::npos)
		cout << "YES\n8\n";
	else if(s.find("0") != string::npos)
		cout << "YES\n0\n";
	else
	{
		solve(0,0);	
		cout << "NO\n";
	}
	return 0;
}
