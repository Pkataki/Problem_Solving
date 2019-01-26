#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005;
const int maxl = 20;

int up[maxn][maxl];

int n, l;
vector<int> graph[maxn];

int timer;
int in[maxn], out[maxn];

void dfs(int v, int p)
{
    in[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : graph[v]) {
        if (u != p)
            dfs(u, v);
    }

    out[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) 
{
    timer = 0;
    l = ceil(log2(n));
    dfs(root, root);
}
