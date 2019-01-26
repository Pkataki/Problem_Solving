#include<bits/stdc++.h>
using namespace std;
int res[300][300];
int sink;
int n;
int vis[300];
int find_path(int u, int flow)
{
	if(u == sink)
		return flow;
	vis[u] = 1;
	for(int i = 0; i <= sink; i++)
    { 
		if(!vis[i] && res[u][i])
		{
			int f = find_path(i, min(flow, res[u][i]));
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

int get_flow()
{
	int ans = 0;
	while(true)
	{
		memset(vis,0,sizeof(vis));
		if(ans += find_path(0,(1 << 29)) == 0)
			break;
	}
}

int main()
{

	for(int w = 0; w < n; w++)
	{
		for(int i = 0; s[i] != 0; i++)
		{
			res[w+1][s[i]-'a'+n+1]++;
		}
	}
	
	
	return 0;
}