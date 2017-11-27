#include<bits/stdc++.h>
using namespace std;
int dp[10050];
int n;
typedef struct job
{
	int start,finish,profit;
}job;
bool cmp(job j1, job j2)
{
	return (j1.finish < j2.finish);
}
job v[10050];
int solve(int at)
{
	if(at >= n)
		return 0;
	if(dp[at] != -1)
		return dp[at];
	int ans = solve(at+1);
	for(int i = at; i <= n; i++)
	{
		if(v[at].finish <= v[i].start)
		{
			ans = max(ans,solve(i)+v[at].profit);
		}
	}
	return dp[at] = ans;
}
main()
{
	int test;
	cin >> test;
	while(test--)
	{
		memset(dp,-1,sizeof(dp));
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> v[i].start >> v[i].finish >> v[i].profit;
		v[n].start = v[n].finish = v[n].profit = (1 << 30);
		cout << (1 << 30);
		sort(v,v+n,cmp);
		cout << solve(0) << "\n";
	}
}
