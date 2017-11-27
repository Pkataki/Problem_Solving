#include<bits/stdc++.h>
using namespace std;
long long dp[61][61][61][61][61];
string s1,s2,s3;
long long solve(int is, int ie, int js, int je, int k)
{
	if ( is > ie || je > js || k > s3.size() )
		return 0;
	long long & ans = dp[is][ie][js][je][k];
	if(ans != -1)
		return ans;
	if ( s1.substr(is, ie-is+1) == s3.substr(0, k) && s2.substr(js, je-js+1) == s3.substr(k))
		return 1;
	ans = 0;
	ans += solve(is+1, ie, js, je, k) + solve(is, ie-1, js, je, k) + solve(is, ie, js+1, je, k) + solve(is, ie, js, je-1, k) + solve(is, ie, js, je, k+1);
	return ans;	
}
main()
{	
	int n;
	cin >> n;
	while(n--)
	{
		memset(dp,-1,sizeof(dp));
		cin >> s1 >> s2 >> s3;
		int sz1, sz2, sz3;
		sz1 = s1.size();
		sz2 = s2.size();
		sz3 = s3.size();
		cout << solve(0,sz1,0,sz3, 0) << "\n";
	}
}
