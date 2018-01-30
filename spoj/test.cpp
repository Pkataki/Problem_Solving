#include<bits/stdc++.h>
using namespace std;
const int maxn = 30011 + 2;
const int maxm = 200011;
struct Tedge {
    int v, next;   
} e[maxm * 2];
int N;
int head[maxn];
void Insert(int x, int y) {
    e[N].v = y;
    e[N].next = head[x];
    head[x] = N;
    N++;   
}
int n, m, t;
int dfn[maxn], anc[maxn], semi[maxn], best[maxn], par[maxn], id[maxn], idom[maxn];
vector<int> dom[maxn];
void Init() {
    scanf("%d%d", &n, &m);
   
    N = 0;
    for (int i = 0; i < n; i++) {
        head[i] = -1;
        anc[i] = i;
        semi[i] = i;
        best[i] = i;
        idom[i] = i;
        id[i] = -1;
        par[i] = -1;
        dfn[i] = 0;
        dom[i].clear();
    }
    int x, y;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        Insert(y, x);
        Insert(x, y);
    }
}
int get(int x) {
    if (x == anc[x]) return x;
    int f = get(anc[x]);
    if (dfn[ semi[ best[x] ] ] > dfn[ semi[ best[ anc[x] ] ] ]) {
        best[x] = best[ anc[x] ];   
    }
    anc[x] = f;
    return f;
}
void Tarjan() {
    for (int y = t; y > 1; y--) {
        int v = id[y];
        int x = par[v];
        for (int i = head[v]; i != -1; i = e[i].next) {
            if (i % 2 == 0) continue;
            int u = e[i].v;
            if (dfn[u] == 0) continue;
            get(u);
            if (dfn[ semi[ best[u] ] ] < dfn[ semi[v] ])
                semi[v] = semi[ best[u] ];   
        }
        dom[ semi[v] ].push_back(v);
        anc[v] = x;
       
        int size = dom[x].size();
        for (int i = 0; i < size; i++) {
            int to = dom[x][i];
            get(to);
            if (dfn[ semi[ best[to] ] ] < dfn[x]) idom[to] = best[to];
            else idom[to] = x;   
        }
        dom[x].clear();
    }
    for (int i = 2; i <= t; i++) {
        int v = id[i];
        if (idom[v] != semi[v]) idom[v] = idom[ idom[v] ];
    }
}
void Dfs(int u) {
    t++;
    dfn[u] = t;
    id[ dfn[u] ] = u;
    for (int i = head[u]; i != -1; i = e[i].next)
        if (dfn[ e[i].v ] == 0 && i % 2 == 0) {
            Dfs(e[i].v);
            par[ e[i].v ] = u;
        }
}
void Solve() {
    t = 0;
    Dfs(n - 1);
    Tarjan();
    for(int i = 0; i< n; i++)
    {
        cout << i+1 << " " << idom[i]+1 << endl;
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
   
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        Init();
        Solve();
    }
    return 0;   
}