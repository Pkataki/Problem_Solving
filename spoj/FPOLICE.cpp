#include<bits/stdc++.h>
using namespace std;
typedef struct state
{
	int risk,_time;
}state;
#define mp(a,b) make_pair(a,b)
state graph[105][105];
pair<int,int> dp[102][251];
int n,t;
pair<int,int> solve( int j, int rtime)
{
	if(j == n-1)
	{
		return mp(0,t-rtime);
	}
	if(dp[j][rtime] != mp(-1,-1))
	{
		return dp[j][rtime];	
	}
	if(rtime < 0)
	{
		return mp(-1,t-rtime);		
	}
	pair<int,int>ans1 = mp((1 << 28),-1);
	for(int i = 0 ; i < 105; i++)
	{
		if(graph[j][i]._time || graph[j][i].risk)
		{
			pair<int,int> aux = solve(i,rtime-graph[j][i]._time);
			aux.first += graph[j][i].risk;
			if(ans1.first > aux.first)
			{
				ans1 = aux;
			}
			else if(ans1.first == aux.first)
			{
				ans1.second = max(ans1.second,aux.second);
			}
		}
	}
	return dp[j][rtime] = ans1;
}
main()
{
	int test;
	cin >> test;
	while(test--)
	{
		memset(graph,0,sizeof(graph));
		memset(dp,-1,sizeof(dp));
		cin >> n >> t;
		for(int i = 0;i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int _time;
				cin >> _time;
				graph[i][j]._time = _time;
			}
		}
		for(int i = 0;i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int risk;
				cin >> risk;
				graph[i][j].risk = risk;
			}
		}
		pair<int,int> ans = solve(0,t);
		if(ans.first == -1)
		cout << "-1\n";
		else
		cout << ans.first << " " << ans.second  << "\n";
	}
}
