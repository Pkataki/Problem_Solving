#include<bits/stdc++.h>
using namespace std;
int d[2005][2005];
int n,m;
bool valid(int x , int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);	
}
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	memset(d,-1,sizeof(d));
	scanf("%d %d",&n,&m);
	int k;
	scanf("%d",&k);
	queue<pair<int,int> >q;
	for(int i = 0; i < k; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;
		b--;
		d[a][b] = 0;
		q.push({a,b});
	}
	while(!q.empty())
	{
		pair<int,int> p = q.front();
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int x = p.first + dx[i];
			int y = p.second + dy[i];
			if( valid(x,y) && d[x][y] == -1)
			{
				d[x][y] = d[p.first][p.second] + 1;
				q.push({x,y});
			}
		}
	}
	int x = 1,y = 1;
	int a = 0;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			if( d[i][j] >= a)
			{
				
				a = d[i][j];
				x = i ;
				y = j;
			}
		}
	}
	cout << x+1 << ' ' << y + 1 << '\n';
	return 0;
}
