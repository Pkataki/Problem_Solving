#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct edge
{
    int u,v,cap,flow;
    long long cost;
};
vector<edge>e;

vector<int>graph[maxn];

long long dist[maxn];
int ptr[maxn], fa[maxn];
const long long inf = 1e18;

void add_edge(int u , int v, int cap, long long cost)
{
    edge e1 = {u,v,cap,0,cost};
    edge e2 = {v,u,0,0,-cost};

    graph[u].push_back(e.size());
    e.push_back(e1);
    
    graph[v].push_back(e.size());
    e.push_back(e2);
}


bool dijkstra(int s, int t)
{
    for(int i = 0 ; i < maxn; i++)
    {
        dist[i] = inf;
        fa[i] = -1;
    }
    set<pair<int,int> >q;
    q.insert({0,s});
    dist[s] = 0;
    while(q.size())
    {
        auto x = *q.begin();
        long long c = x.first;
        int u = x.second;
        q.erase(q.begin());
        if(c > dist[u])
            continue;
        
        for(int i = 0; i < graph[u].size(); i++)
        {
            int id = graph[u][i];
            int v = e[id].v;
            long long cost = e[id].cost;
            if((dist[v] > dist[u] + cost) && (e[id].cap > e[id].flow))
            {
                dist[v] = dist[u] + cost;
                fa[v] = u;
                q.insert({dist[v],v});
            }
        }
    }

    return dist[t] != inf;
}

pair<long long , int > operator + (pair<long long , int > a, pair<long long , int > b)
{
    a.first += b.first;
    a.second += b.second;
    return a;
}

pair<long long, int> dfs(int u , int flow, int t)
{
    if(!flow)
        return {0,0};
    if(u == t)
        return {0,flow};
    for(; ptr[u] < graph[u].size(); ptr[u]++)
    {
        int id = graph[u][ptr[u]];
        int v = e[id].v;
        long long cost = e[id].cost;

        if((fa[v] != u) || (dist[v] != dist[u] + cost))
            continue;
        
        auto x = pair<long long, int>(cost,0) + dfs(v, min(flow, e[id].cap - e[id].flow), t);
        
        if(x.second)
        {
            e[id].flow += x.second;
            e[id^1].flow -= x.second;
            return x;
        }

    }
    return {0,0};
}


auto mcmf(int s, int t)
{
    pair<long long, int> ans(0,0);
    while(dijkstra(s,t))
    {
        memset(ptr,0,sizeof(ptr));
        pair<long long,int> pushed;
        while( (pushed = dfs(s, (1 << 29), t)).second )
            ans = ans + pushed;
    }
    return ans;
}

void clear()
{
    e.clear();
    for(int i = 0 ; i < maxn; i++)
        graph[i].clear();
}

int main() 
{    
    int T;
    scanf( "%d", &T );
    while(T--) 
    {
        clear();
        int V,L;
        scanf( "%d %d", &V, &L);

        int src = 2*V;
        int snk = 2*V + 1;
 
        for(int i = 0 ; i < L; i++)
        {
            int u, v,co;
            scanf( "%d %d %d", &u, &v,&co );
            u--; v--;
            add_edge( u, v+V, 1,co);
        }
        
        for(int i = 0; i < V; i++)
        {
            add_edge(src,i,1,0);
            add_edge(i+V,snk,1,0);
        }
        
        printf( "%lld\n", mcmf(src,snk).first );
    }
 
    return 0;
}