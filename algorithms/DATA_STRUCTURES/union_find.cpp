struct dsu
{
    int rep[maxn];
    long long sz[maxn];

    void init(int n)
    {
        for(int i = 1 ; i <= n; i++)
        {
            rep[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x)
    {
        return rep[x] = (rep[x] == x ? x : find(rep[x]));
    }

    void unio(int x, int y)
    {
        x = find(x);
        y = find(y);

        if(x != y)
        {
            if(sz[x] < sz[y])
                swap(x,y);
            rep[y] = x;
            sz[x] += sz[y];
        }
    }
}d;