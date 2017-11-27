#include<bits/stdc++.h>
using namespace std;
#define uint64 unsigned long long
uint64 dp[5005];
string s;
int fim;
uint64 solve(int idx)
{
	if(idx > fim)
		return 1ULL;
	
	if(dp[idx] != -1)
		return dp[idx];
	if(s[idx] == '0')
		return 0ULL;

	uint64 ans = 0ULL;
	if(idx+1 < fim && ((s[idx] == '1' || s[idx] == '2') && s[idx+1] <= '6'))
	{
		if(s[idx+1] ==  '0')
			ans = solve(idx+2);
		else
			ans = solve(idx+1) + solve(idx+2);
	}
	else
		ans = solve(idx+1);
	
	return dp[idx] = ans;
}

main()
{
	cin.	
	while(1)
	{
		getline(cin, s);
		if (s[0] == '0') break;				
		memset(dp,-1,sizeof(dp));
		fim = s.size();
		cout << solve(0) << "\n";
	}
}
