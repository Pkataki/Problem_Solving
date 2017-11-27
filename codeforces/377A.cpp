#include<bits/stdc++.h>
using namespace std;
string s[1000];
int n,m,k;
vector<pair<int,int> >ans;
int x[] = {0,0,1,-1};
int y[] = {1,-1,0,0};
int vis[505][505];
void dfs(int x1, int y1)
{
	if(vis[x1][y1])
		return;
	vis[x1][y1] = 1;
	ans.push_back(make_pair(x1,y1));
	for(int i = 0; i < 4; i ++)
	{
		int dx = x1 + x[i];
		int dy = y1 + y[i];
		if(dx >=0 && dx< n && dy >=0 && dy < m && s[dx][dy] != '#')
			dfs(dx,dy);
	}
}
int main()
{
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0 ; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(s[i][j] == '.')
			{
				dfs(i,j);
				reverse(ans.begin(),ans.end());
				for(int h = 0; h < k; h++)
				{
					s[ans[h].first][ans[h].second] = 'X';
				}
				for(int h = 0; h < n; h++)
				{
					cout << s[h] << '\n';
				}
				return 0;
			}
		}
	}
}
