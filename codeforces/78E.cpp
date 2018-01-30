#include<bits/stdc++.h>
using namespace std;

typedef struct state
{
	long long x,y,steps,id;
	state(int x,int y,int steps,int id)
	{
		this->x = x;
		this->y = y;
		this->steps = steps;
		this->id = id;
	}
}state;
long long toxic[105][105];
bool visbfs[105][105][105];
int x1[] = {-1,1,0,0};
int y11[] = {0,0,1,-1};
long long res[100][100];
bool vis[100];
long long sink;
long long find_path(int u, long long flow)
{
	if(u == sink)
		return flow;
	vis[u] = 1;
	for(int i = 0; i <= sink; i++)
	{
		if(!vis[i] && res[u][i])
		{
			long long f = find_path(i,min(flow,res[u][i]));
			if(f)
			{
				res[u][i] -= f;
				res[i][u] += f;
				return f;
			}
		}
	}
	return 0;
}
int main()
{
	int n,time;
	cin >> n >> time;
	char mat[n][n],mat2[n][n];
	int mat3[n][n];
	queue<state>q,qt;
	memset(toxic,0x3f3f,sizeof(toxic));
	int INF = toxic[0][0];
	int cont = 1;
	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
			if(mat[i][j] >= '1' && mat[i][j] <= '9')
			{
				int a = (int)(mat[i][j] - '0');
				for(int k = 0; k < a; k++)
				{
					q.push(state(i,j,0,cont));
					cont++;
				}
			}
		}	
	}
	getchar();
	vector<pair<int,long long> >dest;
	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> mat2[i][j];
//			cout << mat2[i][j];
			if(mat2[i][j] >= '1' && mat2[i][j] <= '9')
			{
				dest.push_back(make_pair(i,j));
			}
			else if(mat2[i][j] == 'Z')
			{
				qt.push(state(i,j,0,0));
			}
		}
//		cout << "\n";
	}
	while(!qt.empty())
	{
		state at = qt.front();
		qt.pop();

		if(at.steps >= time)
			continue;
		for(int i = 0; i < 4; i++)
		{
			int x2 = at.x + x1[i];
			int y2 = at.y + y11[i];
			if(!visbfs[x2][y2][0] && mat2[x2][y2] >= '0' && mat2[x2][y2] <= '9' && x2 >= 0 && x2 < n && y2 < n && y2 >= 0)
			{
					visbfs[x2][y2][0] = 1;	
					qt.push(state(x2,y2,at.steps+1,0));		
				//	cout << toxic[x2][y2] << " " << at.steps+1 << " **\n"; 
					toxic[x2][y2] = min(toxic[x2][y2],at.steps+1);
			}
		}
	}
	/*
	for(int i = 0; i < n; i++)
	{	
		for(int j = 0; j < n; j++)
		{
			if(toxic[i][j] == INF)
			cout << -1;
			else
				cout << toxic[i][j];
		}
		cout << "\n";
	}*/
	memset(visbfs,0,sizeof(visbfs));
	while(!q.empty())
	{
		state at = q.front();
		q.pop();
	//	cout << at.x << " ---  " << at.y << " steps: " << at.steps << " **\n";
		bool found = 0;
		if(at.steps == time || at.steps == toxic[at.x][at.y])
		{
			bool fim = 0;
			for(int i = 0; i < dest.size(); i++)
			{
				if(at.x == dest[i].first && at.y == dest[i].second)
				{
					fim = 1;
				}				
			}
			if(!fim)
			{
				continue;	
			}
		}
		if(at.steps > time || (toxic[at.x][at.y] < at.steps && toxic[at.x][at.y] != INF))
			continue;
		for(int i = 0; i < dest.size(); i++)
		{
			if(at.x == dest[i].first && at.y == dest[i].second)
			{
				found = 1;
				res[at.id][cont+i] = 1;
	//			cout << "id: " << at.id << " steps: " << at.steps<<" capsula: "<< cont+i << " --> " << res[at.id][cont+i] << " **\n";
				break;
			}
		}
		for(int i = 0; i < 4; i++)
		{
			int x2 = at.x+x1[i];
			int y2 = at.y+y11[i];
			if(!visbfs[x2][y2][at.id] && mat2[x2][y2] >= '0' && mat2[x2][y2] <= '9' && x2 >= 0 && x2 < n && y2 >= 0 && y2 < n)
			{
				visbfs[x2][y2][at.id] = 1;
				q.push(state(x2,y2,at.steps+1,at.id));
			}
		}
	}
	/*for(int i = 1 ; i <= cont; i++)
	{
		for(int j = 0; j <= n*n; j++)
		{
			if(res[i][j])
			{
				cout << i << " " << j << " --> " << res[i][j] <<" **\n";
			}
		}
	}*/
	sink = cont+dest.size();
//	cout << "sink: " << sink << " **\n";
	for(int i = 1; i < cont; i++)
	{
		res[0][i] = 1;
	}
	for(int i = 0; i < dest.size(); i++)
	{
		res[cont+i][sink] = (int)(mat2[dest[i].first][dest[i].second] - '0');
	}
	/*
	for(int i = 0 ; i <= cont*cont; i++)
	{
		for(int j = 0; j <= cont*cont; j++)
		{
			if(res[i][j])
			{
				cout << i << " " << j << " --> " << res[i][j] <<" **\n";
			}
		}
	}*/
	/*
	for(int i = 1 ; i <= cont; i++)
	{
		for(int j = 0; j < dest.size(); j++)
		{
			cout <<i << " " << cont+j<< " -> " <<res[i][cont+i] << " **\n";	
		}
	}*/
	while(true)
	{
		memset(vis,0,sizeof(vis));
		if(!(find_path(0,(1 << 28))))
			break;
	}
	long long ans = 0;
	
	for(int i = 0; i < dest.size(); i++)
	{
		ans += res[sink][cont+i];
	}
	cout << ans << "\n";
	return 0;
}