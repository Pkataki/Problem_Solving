#include <bits/stdc++.h>
using namespace std;
int mat[21][21];
int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,1,-1};

int n,m;
bool on_limit(int x, int y)
{
	if(x >= 0 && x < n && y >= 0 && y < m)
		return 1;
	return 0;
}
int ans;
void solve(int x, int y, int steps)
{
	for(int i = 0 ; i < 4; i++)
	{
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		int x2 = x + 2*dx[i];
		int y2 = y + 2*dy[i];
		if(on_limit(x1,y1) && mat[x1][y1] == 2 && on_limit(x2,y2) && mat[x2][y2] == 0)
		{
			mat[x1][y1] = 0;	
			ans = max(ans,steps+1);
			solve(x2,y2,steps+1);
			mat[x1][y1] = 2;	
		}
	}
}
int main()
{
	while(cin >> n >> m && (n || m))
	{
		bool ok = 1;
		for(int i = 0 ; i < n; i++)
		{
			ok = ((i & 1) == 0);
			for(int j = 0 ; j < m; j++)
			{
				if(ok)
					cin >> mat[i][j];
				else
					mat[i][j] = -1;
				ok ^= 1;
			}
		}
		
		ans = 0;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0 ; j < m; j++)
			{
				if(mat[i][j] == 1)
				{
					mat[i][j] = 0;
					solve(i,j,0);
					mat[i][j] = 1;
				}
			}
		}
		cout << ans << '\n';
		
	}
	return 0;
}
