#include<bits/stdc++.h>
using namespace std;
char mat[55][55];
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};
bool found;
int vis[55][55];
int n,m;
void dfs(int xi, int yi, int fromx, int fromy, char color)
{
	if(xi < 0 && xi >= n && yi < 0 && yi >= m)
		return ;
	if(mat[xi][yi] != color)
		return;
	if(vis[xi][yi])
	{
		found = 1;
		return;
	}
	vis[xi][yi] = true;
	for(int i = 0; i < 4; i++)
	{
		int x1 = xi + x[i];
		int y1 = yi + y[i];
		if(x1 == fromx && y1 == fromy)
			continue;
		dfs(x1,y1,xi,yi,color);
	}

}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			memset(vis,0,sizeof(vis));
			found = 0;
			dfs(i,j,-1,-1,mat[i][j]);
			if(found)
			{
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}
