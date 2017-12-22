#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int> >q;
char mat[1005][1005];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int vis[1005][1005];
int vi;
map<char,char>mapa;
int n,m;
bool out_limit(int i, int j)
{
	return (i >= n || i < 0 || j >= m | j < 0);
}
int dp[1005][1005];
int dfs(int i, int j)
{
	if(dp[i][j] != -1)
		return dp[i][j];
	if(vis[i][j] == 1)
		return (1 << 30);
	int ans = 0;
	vis[i][j] = 1;
	for(int k = 0; k < 4; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];
		if(out_limit(x,y))
			continue;
		if(mat[x][y] == mapa[mat[i][j]])
		{
			int a = dfs(x,y);
			ans = max(ans,a);
		}
	}	
	if(mat[i][j] == 'A')
		ans++;
	return dp[i][j] = ans;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	mapa['D'] = 'I';
	mapa['I'] = 'M';
	mapa['M'] = 'A';
	mapa['A'] = 'D';

	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < m ; j++)
		{
			cin >> mat[i][j];
			if(mat[i][j] == 'D')
				q.push({i,j});
		}
	}
	int ans = 0;
	while(!q.empty())
	{
		vi++;
		pair<int,int> p = q.front();
		q.pop();
		int a = 0;
		a = dfs(p.first,p.second);
		if(a >= (1 << 29))
		{
			cout << "Poor Inna!\n";
			return 0;
		}
		ans = max(ans,a);
	}
	if(ans == 0)
		cout << "Poor Dima!\n";
	else
		cout << ans << '\n';
	return 0;
}
