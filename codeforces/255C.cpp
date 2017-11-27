#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int> >mapa;
int dp[4005][4005];
int v[4005];
int solve(int i, int j)
{
	if(dp[i][j] != -1)
		return dp[i][j];
	vector<int>::iterator it = lower_bound(mapa[v[i]].begin(),mapa[v[i]].end(),j+1);
	int aux;
	if(it == mapa[v[i]].end())
		aux = -1;
	else
		aux = (*it);
	
	if(aux == -1)
		dp[i][j] = 2;
	else
		dp[i][j] = solve(j,aux)+1;
	return dp[i][j];
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&v[i]);
		mapa[v[i]].push_back(i);
	}
	memset(dp,-1,sizeof(dp));
	int ans = 0;
	if(n == 1)
	{
		puts("1");
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			ans = max(ans,solve(i,j));		
		}
	}
	printf("%d\n",ans);
}
