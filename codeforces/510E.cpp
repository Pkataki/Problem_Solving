#include<bits/stdc++.h>
using namespace std;
int res[300][300];
int sink;
int n;
int vis[300];
vector<int> graph[300];
int find_path(int u, int flow)
{
	//cout << u << " ** " << endl;
	if(u == sink)
		return flow;
	vis[u] = 1;
	for(int i = 1; i <= sink; i++)
	{ 

		if(!vis[i] && res[u][i] > 0)
		{
			//cout << res[u][i] << endl;
			int f = find_path(i, min(flow, res[u][i]));
			if(f)
			{
				res[u][i] -= f;
				res[i][u] += f;
				return f;
			}
		}
	}
	//cout << u << ' ' << res[u][sink] << endl;
	return 0;
}
bool prime[200005];
void sieve()
{
    for(int i=2;i<=2*10000+5;++i)
    {
        if(prime[i]==0)
        {
            for(int j=i*2;j<=2*10000+5;j+=i)
            {
                prime[j]=1;
            }
        }
    }
}
vector<int>ans[200];
void dfs(int c, int u)
{
	ans[c].push_back(u);
	vis[u] = 1;
	for(int i = 0 ; i < graph[u].size(); i++)
	{
		int v = graph[u][i];
		if(!vis[v])
		dfs(c,v);
	}
}
int v[300];
int main()
{
	int n;
	sieve();
	scanf("%d",&n);
	int im = 0, pa = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d",&v[i]);
		if(v[i] & 1)
			im++;
		else
			pa++;
	}
	if(im != pa)
	{
		puts("Impossible");
		return 0;
	}
	sink = n+1;

	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
		{
			if(prime[v[i]+v[j]]  == 0 && (v[i] & 1) )
			{
				//cout << i << ' ' << j << endl; 
				res[i][j] = 1;
				//res[j][i] = 1;
			}
		}
		if(v[i] & 1)
		{
			res[0][i] = 2;
		}
		else
		{
			res[i][sink] = 2;
		}
	}
	
	int flow = 0;
	while(true)
	{
		memset(vis,0,sizeof(vis));
		int a = find_path(0,(1 << 29));
		if(!a)
			break;
		flow += a;
	}
	if(flow != n)
	{
		puts("Impossible");
		return 0;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(v[i] & 1)
			continue;
		for(int j = 1 ; j <= n ; j++)
		{
			if(res[i][j] == 1)
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	memset(vis,0,sizeof(vis));
	int k = 0;
	for(int i = 1 ; i <= n; i++)
	{
		if(vis[i])
			continue;
		dfs(k++,i);
	}
	printf("%d\n",k);
	for(int i = 0; i < k ; i++)
	{
		printf("%d ",(int)ans[i].size());
		for(int j = 0; j < ans[i].size(); j++)
		{
			printf("%d ",ans[i][j]);
		}
		puts("");
	}
	return 0;
}