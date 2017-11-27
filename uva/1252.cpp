#include <bits/stdc++.h>
using namespace std;
int obj[200];
int dp[1 << 11 + 1][1 << 11 + 1];
int n,m;
int solve(int questions, int answers)
{
	if(dp[questions][answers] != -1)
		return dp[questions][answers];
	
	int num_recognized = 0;
	for(int i = 0; i < n; i++)
	{
		if((obj[i] & questions) == answers)	
			num_recognized++;
	}
	if(num_recognized <= 1)
		return 0;
	
	int ans = 500;
	for(int i = 0; i < m ; i++)
	{
		if(questions & (1 << i))
			continue;
		ans = min(ans, 1 + max(solve(questions | (1 << i ), answers), solve(questions | (1 << i), answers |(1 << i))));
	}
	return dp[questions][answers] = ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	while(cin >> m >> n && (n || m))
	{
		memset(dp,-1,sizeof(dp));
		string s;
		for(int i = 0; i < n; i++)
		{
			cin >> s;
			int aux = 0;
				for(int j = 0; j < m ; j++)
			{
				aux |= ((s[j] - '0') << j);
			}
			obj[i] = aux;
		}	
		cout << solve(0,0) << '\n'; 
	}
	return 0;
}
