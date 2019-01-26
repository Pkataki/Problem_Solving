#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2004;

vector<vector<int> > graph, rev_graph;

int used[2*maxn], comp[2*maxn], res[2*maxn];
vector<int>order;

void dfs1(int u)
{
  used[u] = true;
  for (auto &v: graph[u])
  {
    if (!used[v]) 
      dfs1(v);
  }
  order.push_back(u); 
}

void dfs2(int u, int color)
{ 
  comp[u] = color;
  for (auto &v: rev_graph[u])
  {
    if (comp[v] == -1) 
      dfs2(v, color);
  } 
}


bool two_sat()
{ 
  int n = graph.size();
  for (int i = 0; i < n; i++) 
      if (!used[i]) 
          dfs1(i);
  
  for (int i = 0; i < n; i++) 
      for (auto &v : graph[i])
          rev_graph[v].push_back(i);
  
  for (int i = 0, color = 0; i < order.size(); i++)
  {
      int u = order[n-i-1];
      if (comp[u] == -1) 
          dfs2(u, color++); 
  }

  for (int i = 0; i < n; i++) 
  {
      if (comp[i] == comp[i^1]) 
          return false;
  }
  for (int i = 0; i < n; i+=2)
      res[i/2] = (comp[i] > comp[i^1]);
  
  return true; 
}
void init_twosat(int vars)
{
  int n = 2*vars;
  graph.clear(); 
  rev_graph.clear();
  graph.resize(n);
  rev_graph.resize(n);
  order.clear();
  memset(comp, -1, sizeof comp);
  memset(used, 0,  sizeof used);
}

// Add edges of the clause
void add(int x, int y)
{ 
    graph[x].push_back(y);
    graph[y].push_back(x);
}

int normal(int x){ return 2*x; } // not negated
int negated(int x){ return 2*x + 1;} // negated
int neg(int x){ return x ^ 1; }// just for add_clause


//NOTE: add_clause(x, y) : ~x -> y and ~y -> x
void add_clause(int x, int y)
{ 
    add(neg(x), y);
    add(neg(y), x);
}
