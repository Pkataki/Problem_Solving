#include<bits/stdc++.h>
using namespace std;
long long dp[210][210];
bool used;
string s;
long long solve(int l, int r)
{
	if(l > r)
		return 1LL;
	if(dp[l][r] != -1)
		return dp[l][r];
	long long ans = 0LL;
	dp[l][r] = 0LL;
	for(int i = l+1; i <= r; i+=2)
	{
		ans = 1LL;
		if(s[l]=='(' && s[i]==')') ans=1;
        else if(s[l]=='{' && s[i]=='}') ans=1;
        else if(s[l]=='[' && s[i]==']') ans=1;
        else if(s[l]=='?' && s[i]==')') ans=1;
        else if(s[l]=='?' && s[i]=='}') ans=1;
        else if(s[l]=='?' && s[i]==']') ans=1;
        else if(s[l]=='(' && s[i]=='?') ans=1;
        else if(s[l]=='{' && s[i]=='?') ans=1;
        else if(s[l]=='[' && s[i]=='?') ans=1;
        else if(s[l]=='?' && s[i]=='?') ans=3;
        else    ans=0;
		dp[l][r] += ans*solve(l+1,i-1)*solve(i+1,r);
		if(dp[l][r] >= 100000)
		{
			dp[l][r] %= 100000;
			used = 1;
		}
	}
	return dp[l][r];
}
int main()
{
	int n;
	cin >> n ;
	cin >> s;
	memset(dp,-1,sizeof(dp));

	long long ans = solve(0,n-1);
	if(used)
	{
		cout << setfill('0') << setw(5) << ans << '\n';
	}
	else
		cout << ans << '\n';
	return 0;
}
