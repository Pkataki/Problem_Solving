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
	return 0;
}
int main()
{
	string s;
	cin >> s;
	cin >> n;
	sink = n+27;
	for(int i = 0; s[i] != 0; i++)
	{
		res[s[i]-'a'+n+1][sink]++;	
	}
	for(int w = 0; w < n; w++)
	{
		cin >> s >> res[0][w+1];
		for(int i = 0; s[i] != 0; i++)
		{
			res[w+1][s[i]-'a'+n+1]++;
		}
	}
	while(true)
	{
		memset(vis,0,sizeof(vis));
		if(find_path(0,(1 << 29)) == 0)
			break;
	}
	int ans = 0;
	bool ok = 0;
	for(int i = n+1; i <= n+26; i++)
	{	
		if(res[i][sink])
		{
			ok = 1;
			cout << -1 << "\n";
			break;
		}
	}
	if(!ok)
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 26; j++)
			{
				ans += res[n+j][i] * i;
			}
		cout << ans << "\n";
	}
	return 0;
}