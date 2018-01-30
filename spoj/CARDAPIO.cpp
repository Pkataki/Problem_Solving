#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 5005;
 
inline int negated(int var) { return var ^ 1; }
 
namespace TwoSAT {
  int low[2*MAXN], lbl[2*MAXN], belongs_to[2*MAXN];
  bool is_stacked[2*MAXN];
  vector<int> gr[2*MAXN];
  int dfsnum, components, n;
 
  stack<int> scc;
 
  void init(int sz) {
    n = sz;
    for (int i = 0; i < n; ++i) gr[i].clear();
    fill(lbl, lbl + n, -1);
    components = 0;
  }
  void pop()
  {
    belongs_to[scc.top()] = components;
    is_stacked[scc.top()] = false;
    scc.pop();
    
  }
  void dfs(int u) {
    lbl[u] = low[u] = dfsnum++;
 
    scc.push(u);
    is_stacked[u] = true;
 
    for (int v : gr[u]) {
      if (lbl[v] == -1) dfs(v);
      if (is_stacked[v]) low[u] = min(low[u], low[v]);
    }
 
    if (low[u] == lbl[u]) {
      while (!scc.empty() && scc.top() != u) {
        pop();
      }
      pop();
      components++;
    }
  }
 
  void add_or_clause(int x, int y) {
    gr[negated(x)].push_back(y);
    gr[negated(y)].push_back(x);
  }
 
  bool is_solvable() {
    for (int i = 0; i < n; ++i)
      if (lbl[i] == -1) dfs(i);
 
    for (int i = 0; i < n; i += 2) {
      if (belongs_to[i] == belongs_to[i + 1]) return false;
    }
 
    return true;
  }
 
  // is_true assumes that is_solvable was already called and returned true
  bool is_true(int var) {
    // tarjan already produces SCC in reverse topological order of the SCC graph
    // to know if a variable is true we just need to check if the SCC it is in
    // appears earlier than the SCC where its negation is
    return belongs_to[var] < belongs_to[negated(var)];
  }
};
map<string,int>mapa;
int cont;
int process(string s)
{
  string aux = s;
  if(s[0] == '!')
  {
    aux = s.substr(1);
  }
  if(mapa.count(aux))
      return mapa[aux];
  else
      mapa[aux] = cont++;
  return mapa[aux];
}
int main()
{
  int n;
  ios::sync_with_stdio(0);
  //cin.tie(NULL);
  int ins = 1;
  while(cin >> n)
  {
    cont = 1;
    cout << "Instancia " << ins++ << '\n';
    TwoSAT::init(4 * n + 10);
    mapa.clear();
    
    for(int i = 0; i < n ; i++)
    {
      string s,t;
      cin >> s >> t;
      int v = process(s);
      int u = process(t);
      int v1 = 2*v;
      int v2 = 2*u;
      if(s[0] == '!')
        v1++;
      if(t[0] == '!')
        v2++;
      TwoSAT::add_or_clause(v1,v2);
    }
    if(TwoSAT::is_solvable())
      cout << "sim\n\n";
    else
      cout << "nao\n\n";
  }
} 