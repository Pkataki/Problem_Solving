#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005;

vector<int> to_check[2*maxn];

int u[maxn],v[maxn],z[maxn],lo[maxn],hi[maxn],x[maxn],y[maxn];
int ans[maxn];

struct dsu
{
    int rep[maxn];
    int sz[maxn];

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
    int size(int x)
    {
        return sz[find(x)];
    }
}d;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < m ; i++)
    {
        scanf("%d %d",&u[i],&v[i]);
    }
    int q;
    scanf("%d",&q);
    for(int i = 0; i < q ; i++)
    {
        scanf("%d %d %d",&x[i], &y[i], &z[i]);
        lo[i] = 0;
        hi[i] = m-1;
    }
    bool check = true;

    while(check)
    {
        d.init(n);
        for(int i = 0; i < m; i++)
        {
            to_check[i].clear();
        }
        for(int i = 0; i < q; i++)
        {
            if(lo[i] <= hi[i])
            {
                to_check[(lo[i] + hi[i]) >> 1].push_back(i);
            }
        }
        check = false;
        for(int i = 0; i < m; i++)
        {
            d.unio(u[i],v[i]);
            for(auto &q: to_check[i])
            {
                check = true;
                int val = 0;
                if(d.find(x[q]) == d.find(y[q]))
                {
                    val += d.size(x[q]);
                }
                else
                {
                    val += d.size(x[q]) + d.size(y[q]);
                }
                if(z[q] <= val)
                {
                    ans[q] = i;
                    hi[q] = i - 1;
                }
                else
                {
                    lo[q] = i + 1;
                }
            }
        }

    }

    for(int i = 0; i < q; i++)
    {
        printf("%d\n",ans[i]+1);  
    }

	return 0;
}
