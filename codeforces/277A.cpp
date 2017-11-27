#include <bits/stdc++.h>
using namespace std;
map<int,int>language;
int graph[250][250];
int vis[250];
int n, m;
void dfs(int at)
{
	vis[at] = 1;
	for(int i = 0; i < n + m; i++)
	{
		if(graph[at][i] == 1 && vis[i] == 0)
		{
			dfs(i);
		}
	}
}

int main()
{
	cin >> n >> m;
	int cont = 0;
	int k;
	for(int i = 0; i < n; i++)
	{
		cin >> k;
		cont += k;
		for(int j = 0; j < k; j++)
		{
			int a;
			cin >> a;
			a--;
			graph[i][a + n] = 1;			
			graph[a + n][i] = 1; 

		}
	}
	int ans = 0;
	for(int i = 0; i < n ; i++)
	{
		if(vis[i] == 0)
		{
			dfs(i);
			ans++;
		}
	}
	if(cont == 0)
		cout << n << '\n';
	else
		cout << ans - 1 << "\n";
	
	return 0;
	
}
