#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int NIL = 0;
const int inf = 1 << 29;
int dist[maxn];
int match[maxn];
vector<int>graph[maxn];
bool bfs(int n)
{
    queue<int>q;
    for(int i = 1 ; i <= n ; i++)
    {
        if(match[i] == NIL)
        {
            dist[i] = 0;
            q.push(i);
        }
        else
            dist[i] = inf;
    }
    dist[NIL] = inf;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        if(u == NIL)
            continue;
        for(int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(dist[match[v]] == inf)
            {
                dist[match[v]] = dist[u] + 1;
                q.push(match[v]);
            }
        }
    }
    return dist[NIL] != inf;
}

int dfs(int u)
{
    if(u != NIL)
    {
        for(int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];

            if(dist[match[v]] == dist[u] + 1)
            {
                if(dfs(match[v]))
                {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = inf;
        return false;
    }
    return true;
}
int hopcroft(int n)
{
    int ans = 0;
    while(bfs(n))
    {
        for(int i = 1; i <= n ; i++)
            if(match[i] == NIL && dfs(i))
                ans++;
    }
    return ans;
}
int main()
{
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    for(int i = 0; i < p ; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u].push_back(v+n);
        graph[v+n].push_back(u);
    }
    printf("%d\n",hopcroft(n));
    return 0;
}
