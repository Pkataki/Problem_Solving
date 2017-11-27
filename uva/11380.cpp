#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500; // число вершин
const int INF = 1000000000; // константа-бесконечность
 
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
string graph[MAXN];
int x[] = {0,0,-1,1};
int y[] = {1,-1,0,0};
int mat[MAXN][MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	int nn,m,p;

	
	while(cin >> nn >> m >> p)
	{
		clear();
		for(int i = 0; i < nn ; i++)
		{
			cin >> graph[i];
			
		}
		int cont = 0;
		for(int i = 0; i < nn; i++)
		{
			for(int j = 0; j < m ; j++)
				mat[i][j] = cont++;
		}
		//cout << "passei " << endl;
		n = 3*nn*m + 10;
		s = 3*nn*m + 5;
		t = 3*nn*m + 7;
		int a,b;
		for(int i = 0; i < nn; i++)
		{
			for(int j = 0; j < m; j++)
			{
				a = i * nn + j;
				if(graph[i][j] == '#')
				{
					add_edge(mat[i][j],mat[i][j] + cont,INF);
					add_edge(mat[i][j],t,p);
				}
				else if(graph[i][j] == '*')
				{
					add_edge(s,mat[i][j],1);
					add_edge(mat[i][j],mat[i][j] + cont,1);
				}
				else if(graph[i][j] == '.')
				{
					add_edge(mat[i][j],mat[i][j] + cont,1);
				}
				else if(graph[i][j] == '@')
				{
					add_edge(mat[i][j],mat[i][j] + cont,INF);
				}

				if(graph[i][j] != '~')
				{

					for (int k = 0; k < 4; k++)
					{
						int dx = i + x[k];
						int dy = j + y[k];
						//b = dx * nn + dy;
						if(dx >= 0 && dx < nn && dy >= 0 && dy < m && graph[dx][dy] != '~')
						{
							add_edge(mat[i][j] + cont, mat[dx][dy] ,INF);
						}
					}
				}
				
			}
		}
		cout << dinic() << '\n';
	}
	return 0;
}