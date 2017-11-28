#include<bits/stdc++.h>
using namespace std;
int dp[25][25][410][410];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int row,col;
vector<string>m;
int ob;
class MovingCandies
{
	int solve(int x, int y, int need, int used )
	{
		if(need + used > ob)
		{
			return INT_MAX;
		}
		if(x == row -1 && y == col-1)
		{
			if(m[x][y] == '#')
				used++;
			else
				need++;
			if(need + used > ob)
				return INT_MAX;
			return need;
		}
		int &ans = dp[x][y][need][used]
		if(ans != -1)
		{
			return ans; 
		}
		ans = INT_MAX;
		for(int i = 0; i < 4; i++)
		{
			int x1 = x +dx[i];
			int y1 = y +dy[i];
			if(x1 >= 0 && x1 < row && y1 >= 0 && y < col)
			{
				int aux = INT_MAX;
				if(m[x1][y1] == '#')
					aux = solve(x1,y1,need,used+1);
				else
					aux = solve(x1,y1,need+1,used);
				ans = min(ans,aux);
			}
		}
		return ans;
	}
	public : minMoved(vector<string>t)
	{
		memset(dp,-1,sizeof(dp));
		col = t[0].size();
		row = t.size();
		for(int i= 0; i < t.size(); i++)
		{
			for(int j = 0; j < t[0].size(); j++)
			{
				ob += bool(t[i][j] == '#');
			}
		}
		m = t;
		int ans = solve(0,0,0,0);
		if(ans == INT_MAX)
			return -1;
		else
			return ans;
	}	
};