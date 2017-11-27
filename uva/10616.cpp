#include<bits/stdc++.h>
using namespace std;
int dp[300][300][50];
int m,d,q,n;
int v[300];
int solve(int pos, int sum, int qt)
{
	if(sum == 0 && qt == m)
		return 1;
	if(qt == m && sum != 0)
		return 0;
	if(pos == n)
		return 0;

	if(~dp[pos][sum][qt])
		return dp[pos][sum][qt];
	
	dp[pos][sum][qt] = 0;
	
	return dp[pos][sum][qt] += solve(pos+1,(sum+v[pos])%d, qt+1) + solve(pos+1,sum%d,qt);
}
int main()
{
	int s = 1;
	while(cin >> n >> q && n && q)
	{
		for(int i = 0; i < n; i++)
			cin >> v[i];
		cout << "SET " << s << ":\n";
		s+=1;
		int qq = 1;
		while(q--)
		{
			cin >> d >> m;
			memset(dp,-1,sizeof(dp));
			cout << "QUERY " << qq << ": "<<  solve(0,0,0) << '\n';
			qq++;
		}
	}
	return 0;
}
