#include <bits/stdc++.h>
using namespace std;
struct node
{
	vector <string> mat;
	int steps;
	node(vector<string>mat, int steps) : mat(mat), steps(steps) {}
};
int dist(int x, int y, int x1, int y1)
{
	return abs(x - x1) + abs(y - y1);
}
int dx[] = {0,0,1,1,1,-1,-1,-1};
int dy[] = {1,-1,0,1,-1,0,1,-1};
bool on_limit(int x, int y)
{
	return (x >= 0 && x < 9 && y >= 0 && y < 8);
}
int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	while(test--)
	{
		map<vector<string>,int>mapa;
		vector<string>mat(10);
		pair<int,int>init;
		for(int i = 0 ; i < 9; i++)
		{
			cin >> mat[i];
			for(int j = 0; j < mat[i].size(); j++)
			{
				if(mat[i][j] == 'S')
				{
					init = make_pair(i,j);
				}
			}
		}
		queue<node>q;
		q.push(node(mat,0));
		bool ans = 0;
		while(!q.empty())
		{
			node at = q.front();
			q.pop();
			
			if(at.steps >= 10)
			{
				break;
			}
			bool ok = 1;
			pair<int,int>init;
			vector<pair<int,int> >v;
			for(int i = 0; i < 9; i++)
			{
				for(int j = 0; j < 8; j++)
				{
					if(at.mat[i][j] == 'E')
					{
						ok = 0;
						at.mat[i][j] = '.';
						v.push_back(make_pair(i,j));
					}
					if(at.mat[i][j] == 'S')
					{
						at.mat[i][j] = '.';
						init = make_pair(i,j);
					}
				}
			}
			
			if(ok)
			{
				ans = 1;
				break;
			}

			vector<string>aux;
			
			for(int i = 0; i < 8; i++)
			{
				aux = at.mat;
				int x = init.first + dx[i];
				int y = init.second + dy[i];
				
				if(!on_limit(x,y) || aux[x][y] != '.')
					continue;
				aux[x][y] = 'S';
				vector<pair<int,int> >ships;
				for(int j = 0; j < v.size(); j++)
				{
					pair<int,int> boat = v[j];
					int ma = INT_MAX;
					for(int k = 0; k < 8; k++)
					{
						int x1 = boat.first + dx[k];
						int y1 = boat.second + dy[k];
						if(on_limit(x1,y1))
						{
							int a = dist(x,y,x1,y1);
							ma = min(a,ma);
						}
					}
					
					for(int k = 0; k < 8; k++)
					{
						int x1 = boat.first + dx[k];
						int y1 = boat.second + dy[k];
						if(on_limit(x1,y1) )
						{
							int a = dist(x,y,x1,y1);
							if(a == ma)
							{
								ships.push_back(make_pair(x1,y1));
							}
						}
					}
				}
				bool ok1 = 1;
				cout << ships.size() << " *******\n";
				for(int j = 0 ; j < ships.size(); j++)
				{
					
					if(aux[ships[j].first][ships[j].second] == '.')
						aux[ships[j].first][ships[j].second] = 'E';
										
					else if(aux[ships[j].first][ships[j].second] == 'E' || aux[ships[j].first][ships[j].second] == '#')
						aux[ships[j].first][ships[j].second] = '#';
				
					else
					{
						ok1 = 0;
						break;
					}

				}
				if(!mapa.count(aux) && ok1)
				{
					q.push(node(aux,at.steps+1));
					mapa[aux] = 1;
				}
				for(int i = 0; i < 9; i++)
				{
					for(int j = 0; j < 8; j++)
					{
						cout << aux[i][j];
					}
					cout << '\n';
				}
				cout << "\n\n\n";
			}
			
		}
		if(ans)
			cout << "I'm the king of the Seven Seas!\n";
		else
			cout << "Oh no! I'm a dead man!\n";
	}
	return 0;
}
