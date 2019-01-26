#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAXN = 200000 + 10;

namespace DominatorTree {
  int dfn[MAXN], pre[MAXN], pt[MAXN], sz;
  int semi[MAXN], dsu[MAXN], idom[MAXN], best[MAXN];
  int get(int x) {
    if (x == dsu[x]) return x;
    int y = get(dsu[x]);
    if (semi[best[x]] > semi[best[dsu[x]]]) best[x] = best[dsu[x]];
    return dsu[x] = y;
  }
  void dfs(int u, const VI succ[]) {
    dfn[u] = sz; pt[sz ++] = u;
    for (auto &v: succ[u]) if (!~dfn[v]) {
      dfs(v, succ); pre[dfn[v]] = dfn[u];
    }
  }
  void tarjan(const VI pred[], VI dom[]) {
    for (int j = sz - 1, u; u = pt[j], j > 0; -- j) {
      for (auto &tv: pred[u]) if (~dfn[tv]) {
        int v = dfn[tv]; get(v);
        if (semi[best[v]] < semi[j]) semi[j] = semi[best[v]];
      }
      dom[semi[j]].push_back(j);
      int x = dsu[j] = pre[j];
      for (auto &z: dom[x]) {
        get(z);
        if (semi[best[z]] < x) idom[z] = best[z];
        else idom[z] = x;
      }
      dom[x].clear();
    }
    for (int i = 1; i < sz; ++ i) {
      if (semi[i] != idom[i]) idom[i] = idom[idom[i]];
      dom[idom[i]].push_back(i);
    }
  }
  void build(int n, int s, const VI succ[], const VI pred[], VI dom[]) {
    for (int i = 0; i < n; ++ i) {
      dfn[i] = -1; dom[i].clear();
      dsu[i] = best[i] = semi[i] = i;
    }
    sz = 0; dfs(s, succ); tarjan(pred, dom);
  }
}

using DominatorTree::dfn;
using DominatorTree::idom;

VI pred[MAXN], succ[MAXN], dom[MAXN];

int a[MAXN], b[MAXN]

int main() {
  while (scanf("%d%d", &n, &m) == 2)
  {
    for (int i = 0; i < n + m; ++ i) 
    {
      pred[i].clear(); succ[i].clear();
    }
    for (int i = 0; i < m; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      a[i] = --u; b[i] = --v;
      succ[u].push_back(v);
      pred[v].push_back(u);
    }
    DominatorTree::build(n, 0, succ, pred, dom);
  }
  return 0;
}