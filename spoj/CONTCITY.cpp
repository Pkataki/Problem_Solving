#include<bits/stdc++.h>
using namespace std;
int su[55];
int dist[55][55];
int di[55],p[55],cap[55];
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100; 
const int INF = 1000000000; 
 
struct edge {
	int a, b, cap, flow;
};
 
int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
 
void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}
void clear()
{
	for(int i = 0; i < MAXN; i++)
		g[i].clear();
}
bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	//cout << d[s] << "  " << d[t] << endl;
	
	return d[t] != -1;
}
 
int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		
		//cout << "flow: " << flow  << " DIST T: " << d[t] << endl;

		memset (ptr, 0, n * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int nn,m,h;
		scanf("%d %d %d",&nn,&m,&h);
		int sum = 0;
		for(int i = 1 ; i <= nn ; i++)
		{
			scanf("%d",&su[i]);
			sum += su[i];
		}
		for(int i = 1; i <= nn;i++)
		{
            dist[i][i] = 0;    
            for(int j = i + 1; j <= nn ; j++)
                dist[i][j] = dist[j][i] = INF;
        }
		for(int i = 0; i < m ; i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			dist[a][b] = min(c,dist[a][b]);
			dist[b][a] = dist[a][b];
		}
		for(int i = 1 ; i <= h ; i++)
		{
			scanf("%d %d %d",&di[i], &p[i], &cap[i]);
		}
		for(int k = 1; k <= nn ; k++)
		{
			for(int i = 1; i <= nn ; i++)
			{
				for(int j = 1; j <= nn ; j++)
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					//cout << dist[i][j] << ' ';
				}
			}
		}
		//cout << endl;
		int lo = 0, hi = 100000000;
		int ans = hi;
		s = nn+h+6;
		t = nn+h+5;
		n = nn+h+10;

		while(lo <= hi)
		{
			int mid = (lo + hi) >> 1;
			clear();
			for(int i = 1; i <= nn ; i++)
			{
				add_edge(s,i,su[i]);
			}
			for(int i = 1; i <= h; i++)
			{
				add_edge(nn+i,t,cap[i]);
			}
			for(int i = 1 ;i <= nn; i++)
			{
				for(int j = 1; j <= h; j++)
				{
					if(dist[i][p[j]] <= mid && di[j] <= mid)
						add_edge(i,nn+j,INF);
				}
			}
			int a = dinic();
		//	cout << a << endl;
			if(a == sum)
			{
				hi = mid -1 ;
				ans = mid;
			}
			else
				lo = mid+1;
		}
		clear();
		//cout << lo << " ** " <<endl;
		for(int i = 1; i <= nn ; i++)
		{
			add_edge(s,i,su[i]);
		}
		for(int i = 1; i <= h; i++)
		{
			add_edge(nn+i,t,cap[i]);
		}
		for(int i = 1 ;i <= nn; i++)
		{
			for(int j = 1; j <= h; j++)
			{
				if(dist[i][p[j]] <= ans && di[j] <= ans)
					add_edge(i,nn+j,INF);
			}
		}
		int ans1 = dinic();
		if(ans1 == sum)
			printf("All people can be rescued in %d day(s).\n",ans);
        else 
        	printf("%d survivor(s) can be rescued.\n",ans1);
			
	}

	return 0;
}