#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100020];
pair<int,int>dp[100020][2];
const int MOD = 10007;
pair<int,int> solve(int v, int take, int pai)
{

	if(dp[v][take] != pair<int,int>(-1,-1))
		return dp[v][take];
	pair<int,int> ans,aux;
	pair<int,int> t1(0,1);
	pair<int,int> t2(1,1);
	
	if(take || pai == -1)
	{
		for(int i = 0 ; i < graph[v].size(); i++)
		{
			if(graph[v][i] == pai)
				continue;
		
			aux = solve(graph[v][i],0,v);
			t1.first += aux.first;
			t1.second = (t1.second * aux.second) % MOD;
		}
	}
	else t1 = make_pair(INT_MAX, 1);

	for(int i = 0 ; i < graph[v].size(); i++)
	{
		if(graph[v][i] == pai)
			continue;

		aux = solve(graph[v][i],1,v);
		
		t2.first += aux.first;
		t2.second = (t2.second * aux.second) % MOD;
	}

	if( t1.first < t2.first ) ans = t1;
	else if( t2.first < t1.first ) ans = t2;
	else ans = make_pair(t2.first, (t1.second + t2.second) % MOD);

	return dp[v][take] = ans;
}

int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		for(int i = 0 ; i < 100020; i++)
		{
			graph[i].clear();
			dp[i][0] = dp[i][1] = pair<int,int>(-1,-1);
		}
		for(int i = 0 ; i < n-1; i++)
		{
			int a,b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		pair<int,int>ans1 = solve(1,0,-1);
		cout << ans1.first << ' ' << ans1.second << '\n';
		
	}
	return 0;
}
