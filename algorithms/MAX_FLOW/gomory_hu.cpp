int p[maxn];
int c[250][250];
void gomory_hu_tree(int n)
{
    for(int i = 1; i <= n; i++) 
        p[i] = 1;
    for(int i = 2; i <= n; i++)
    {
        int Flow = dinic(i, p[i]);
        c[i][p[i]] = c[p[i]][i] = Flow;
        for(int j = i+1; j <= n; j++)
            if(dist[j] >= 0 && p[j] == p[i])
                p[j] = i;
        for(auto &x: e)
        {
            x.flow = 0;
        }
        for(int j = 1; j < i; j++)
            c[i][j] = c[j][i] = min(Flow, c[p[i]][j]);
    }
}