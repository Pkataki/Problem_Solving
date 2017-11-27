#include <bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
int mf,f,s,t;
vector<int>p(150);
int res[150][150];
vector<vector<int> >graph(110);
int n;
void augment(int v, int min_edge)
{
	if(v == s)
	{
		f = min_edge;
		return;
	}
	else if(p[v] != -1)
	{
		augment(p[v],min(min_edge,res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}
int edmond_karp()
{
	mf = 0;
	while(true)
	{
		f = 0;
		vector<int>vis(105);
		vis[s] = 1;
		queue<int>q;
		q.push(s);
		p.assign(110,-1);
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			if(u == t)
				break;
			for(int i = 0; i < graph[u].size(); i++)
			{
				int v = graph[u][i];
				if(res[u][v] > 0 && !vis[v])
				{
					vis[v] = 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t,(1 << 28));
		if(f == 0)
			break;
		mf += f;
		
	}
	return mf;
}/*
main()
{
	int k = 0;
	while(scanf("%d",&n) && n)
	{
		memset(res,0,sizeof(res));
		int c;
		scanf("%d %d %d",&s,&t,&c);
		int de,para,peso;
		for(int w = 1; w <= c; w++)
		{
			scanf("%d %d %d",&de,&para,&peso);
			graph[de].push_back(para);
			graph[para].push_back(de);
			res[de][para] += peso;
			res[para][de] += peso;
			//printf("w:%d de:%d para:%d peso:%d\n",w,de,para,peso);
		}
		printf("Network %d\nThe bandwidth is %d.\n\n",++k,edmond_karp());
	}
}*/	
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m;
	while(cin >> n >> m && (n+m != 0))
	{
		s = n+20;
		t = n+21;
		for(int i = 0 ; i < n; i++)
		{
			int a,b,c;
			cin >> a >> b >> c;

			graph[s].push_back(i);
			graph[i].push_back(s);
			res[s][i] += a;
			res[i][s] += a;
			//add_edge(s,i,a);
			for(int j = b; j <= c; j++)
			{
				graph[n+j].push_back(i);
				graph[i].push_back(n+j);
				res[n+j][i] += 1;
				res[i][n+j] += 1;
			}
			
			
		}

		for(int i = 0; i < 10; i++)
		{
			graph[n+i].push_back(t);
			graph[t].push_back(n+i);
			res[t][n+i] += m;
			res[n+i][t] += m;
		}
		int ans = edmond_karp();
	}

	return 0;
}