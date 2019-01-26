#include<bits/stdc++.h>
using namespace std;
const int maxn = 256*256+256;
queue<int> graph[maxn];
int deg[maxn];
stack<int>euler_path;
void dfs(int u)
{
	while(graph[u].size())
	{
		int v = graph[u].front();
		graph[u].pop();
		dfs(v);
	}
	euler_path.push(u);
}
int beg = 0;
bool valid()
{
	int cont1 = 0;
	int cont2 = 0;
	for(int i = 0; i < maxn; i++)
	{
		if(deg[i] == 1)
			cont1++, beg = i;
		else if(deg[i] == -1)
			cont2++;
		else if(deg[i])
		{
			puts("NO");
			return 0;
		}
	}
	if(cont1 != cont2 || cont1 > 1 || cont2 > 1)
	{
		puts("NO");
		return 0;
	}
	return 1;
}
int main()
{
	int n;
	
	for(int i = 0 ; i < n ; i++)
	{
	
		graph[u].push(v);
		deg[u]++;
		deg[v]--;
		beg = u;
	}
	dfs(beg);
	if(euler_path.size() != n+1)
	{
		puts("NO");
		return 0;
	}
	
	return 0;
}