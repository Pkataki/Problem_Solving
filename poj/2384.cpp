#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
char mat[30][30];
struct node
{
	int x,y,cx,cy,d;
	node(int x, int y, int cx, int cy, int d) : x(x) , y(y) , cx(cx) , cy(cy), d(d) {}
};
int n;
int vis[30][30][30][30];
bool on_limit(int x,int y)
{
	return (x < n && x >= 0 && y < n && y >= 0 && mat[x][y] != '#');
}

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int main()
{
	int sx,sy;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
			if(mat[i][j] == '*')
			{
				sx = i;
				sy = j;
			}
		}
	}
	
	queue<node>q;
	for(int i = 0; i < 4; i++)
	{
		int x = sx + dx[i];
		int y = sy + dy[i];
		if(on_limit(x,y))
		{
			vis[x][y][sx][sy] = 1;
			q.push(node(x,y,sx,sy,0));
		}
	}
	int ans = 0;
	
	while(!q.empty())
	{
		node at = q.front();
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int x = at.x + dx[i];
			int y = at.y + dy[i];
			if(on_limit(x,y) && !(x == at.cx && y == at.cy))
			{
				if(((at.x - dx[i]) == at.cx) && ((at.y - dy[i]) == at.cy))
				{
					if(!vis[x][y][at.x][at.y])
					{	
						ans = max(ans,at.d+1);
						vis[x][y][at.x][at.y] = 1;
						q.push(node(x,y,at.x,at.y,at.d+1));
					}
				}
				if(!vis[x][y][at.cx][at.cy])
				{	
					vis[x][y][at.cx][at.cy] = 1;
					if(!(at.cx == sx && at.cy == sy))
					{
						ans = max(ans,at.d+1);
						q.push(node(x,y,at.cx,at.cy,at.d+1));
					}
				}
			}
		}
	}
	cout << ans << '\n';

}
