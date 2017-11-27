#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=200005;

vector<vector<int> > graph, rev_graph;

int used[2*MAXN], comp[2*MAXN], order[2*MAXN], res[2*MAXN], cnt = 0;

void dfs1(int u)
{
  used[u] = true;
  for (auto i = 0u; i < graph[u].size(); i++)
  {
    int v = graph[u][i];
    if (!used[v]) 
      dfs1(v);
  }
  order[cnt++] = u; 
}

void dfs2(int u, int color)
{ 
  comp[u] = color;
  for (auto i = 0u; i < rev_graph[u].size(); i++)
  {
    int v = rev_graph[u][i];
    if (comp[v] == -1) 
      dfs2(v, color);
  } 
}


bool twosat() { 
  int n = graph.size();
  for (int i = 0; i < n; i++) 
      if (!used[i]) 
          dfs1(i);
  
  for (int i = 0; i < n; i++) 
    for (auto j = 0u; j < graph[i].size(); j++)
      rev_graph[graph[i][j]].push_back(i);
  
  for (int i = 0, color = 0; i < n; i++)
  {
    int u = order[n-i-1];
    if (comp[u] == -1) 
      dfs2(u, color++); 
  }

  for (int i = 0; i < n; i++) 
      if (comp[i] == comp[i^1]) 
          return false;
  
  for (int i = 0; i < n; i+=2) 
    res[i/2] = (comp[i] > comp[i^1]);
  
  return true; 
}
void init_twosat(ll vars)
{
  ll n=2*vars;
  graph.clear(); 
  rev_graph.clear();
  graph.resize(2*n);
  rev_graph.resize(2*n);
  memset(order, 0, sizeof order);
  memset(comp, -1, sizeof comp);
  memset(used, 0,  sizeof used);
  memset(res,0,sizeof(res));
  cnt=0;
}

//if type = 0, we add the edge (~x v y), if type = 1, we add the edge (x v y)
//if type = 2, we add the edge (~x v ~y), if type = 3, we add the edge (x v ~y)

//NOTE: add_egde add the implications on form x -> y.
void add(int x, int y)
{ 
    graph[x].push_back(y); 
}

void add_edge(int x, int y, int type)
{ 
  int a=2*x, na=2*x+1, b=2*y, nb=2*y+1;
  switch (type) 
  {
    case 0: 
      add(a,b); 
      add(nb, na); 
      break;
    
    case 1: 
      add(na, b); 
      add(nb, a); 
      break;

    case 2: 
      add(a, nb); 
      add(b, na); 
      break;

    case 3: 
      add(na, nb); 
      add(b,a); 
      break; 
  } 
}

vector<int> v[100005];
int main()
{
	int n,m;
	
	cin >> n >> m;
	init_twosat((ll) m);
	for(int i = 0; i < n ; i++)
	{
		int k;
		cin >> k;
		for(int j = 0; j < k; j++)
		{
			int a;	
			cin >> a;
			v[i].push_back(a);
		}
	}
	for(int i = 0; i < n - 1; i++)
	{
		int mi = min((int)v[i].size(),(int)v[i+1].size());
		bool dif = false;

		for(int j = 0; j < mi; j++)
		{

			int a = v[i][j];
			int b = v[i+1][j];
			if(a == b)
				continue;	
			dif = true;
			if(a < b)
			{	
				add_edge(a,b,3);
			}
			else
			{
				add_edge(a,a,1);
				add_edge(b,b,2);
			}
			break;
		}
		if(!dif)
		{
			if(v[i].size() > v[i+1].size())
			{
				cout << "No\n";
				return 0;
			}
		}
	}
	if(twosat())
	{
		vector<int>ans;

		cout << "Yes\n";
		for(int i = 1; i <= m; i++)
		{
			if(res[i])
				ans.push_back(i);
		}
		cout << ans.size() << '\n';
		for(int i = 0 ; i < ans.size() ; i++)
		{
			cout << ans[i] << " \n"[i == ans.size()-1];
		}
	}
	else
	{
		cout << "No\n";
	}
	return 0;	
}
