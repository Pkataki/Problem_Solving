#include<bits/stdc++.h>
using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))

struct Edge
{
    int u, v, next;
    long long cost, cap;
} e[2000000];  //maximum edge = 5000

int source, sink,  edgenum, first[3000], par[3000];   //maximum node = 100
int rec[3000],vis[3000];
long long  dist[3000], C;

void addEdge( int u, int v, long long f, long long c)
{
    e[edgenum].u = u;
    e[edgenum].v = v;
    e[edgenum].cost = c;
    e[edgenum].cap = f;
    e[edgenum].next = first [u];
    first[u] = edgenum;
    edgenum++;
    
	e[edgenum].u = v;
    e[edgenum].v = u;
    e[edgenum].cost = -c;
    e[edgenum].cap = 0;
    e[edgenum].next = first [v];
    first[v] = edgenum;
    edgenum++;
}

void SPFA(int node)
{
    deque < int > q;

    for ( int i = 0 ; i <= node; i++)
		dist[i] = LLONG_MAX;
    
//   SET(par);
    dist[source] = 0;
    vis[source] = 1 ;

    q.push_front(source);
    while (!q.empty ())
    {
        int u = q.front();
        vis[u] = 0 ;
        q.pop_front();
//		cout << u << " node **\n";

        for ( int k = first[u]; k != - 1 ; k = e[k].next)
        {
            int v = e[k].v;
//			cout << "--> " << v << endl;
  //          cout << "cap: " << e[k].cap << " dist node: " << dist[u] << " cost: " << e[k].cost << " dist v: " << dist[v] << endl;
			if (e[k].cap > 0 && (dist[u] + e[k].cost) < dist[v])
            {
	//			cout << "entrei\n";
                par[v] = u;
                dist[v] = dist[u] + e[k].cost;
                rec[v] = k;
				if (!vis[v])
                {
                    vis[v] = 1 ;
					if(q.size() && dist[q.front()] > dist[v])
                    	q.push_front(v);
                	else
                    	q.push_back(v);
						
				}
            }
        }
    }
    return;
}

int mincost_maxflow (int node)
{
    long long F=0, mn;
    C=0;
	CLR(vis);
    SET(par);
	while ( 1 )
    {
        SPFA (node);
        if (dist[sink] == LLONG_MAX)  
			break ;
        mn= LLONG_MAX;
        for ( int k = sink; k != source ; k = par[k])
		{
			int r = rec[k];
            mn=min(mn, max(0LL,e[r].cap));
        }
		for ( int k = sink; k != source ; k = par[k])
        {
			int r = rec[k];
            e[r].cap -= mn;
            e[r^1].cap += mn;
            e[r^1].cost = -e[r].cost;
        }
        F += mn; 
        C += mn * dist [sink];
	}
    return F;
}


int read()
{
    static char s[16];
    scanf("%s", s);
    if (s[0] == '-')
		return -1;
    int i, x = 0;
    for (i = 0; s[i] && s[i] != '.'; i++)
        x = x * 10 + s[i] - '0';
    if (!s[i])
		return x * 100;
    i++;
    x = x * 10 + s[i] - '0';
    if(!s[i+1])
		return x * 10;
    i++;
    x = x * 10 + s[i] - '0';
    return x;
}

int main()
{
	int cases = 0;
	int n,m;
	int slices[55];
	int scoops[55];
	int mat[55][55];
	while(scanf("%d %d",&n,&m) == 2 && n || m)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&slices[i]);
		}
		for(int i = 0; i < m; i++)
		{
			scanf("%d",&scoops[i]);
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{				
				mat[i][j] = read();
			}
		}
		edgenum = 0;
		SET(first);
		source = n+m;
		sink = n+m+1;
		
		for(int i = 0; i < n; i++)
		{
			addEdge(source, i ,(long long)slices[i],0 );
		}
		for(int i = 0; i < m; i++)
		{
			addEdge(i+n, sink ,(long long)scoops[i],0 );
		}
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(mat[i][j] < 0)
					continue;
				addEdge(i, j + n,0x3f3f3f3f,(long long)mat[i][j]);
			}
		}
		
		mincost_maxflow(n+m+5);
		long long ans1 = C;
		
		edgenum = 0;
		SET(first);
		for(int i = 0; i < n; i++)
		{
			addEdge(source, i ,(long long)slices[i],0LL );
		}
		for(int i = 0; i < m; i++)
		{
			addEdge(i+n, sink ,(long long)scoops[i],0LL );
		}
		int val = 50 * 100 * 2000;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(mat[i][j] < 0)
					continue;
				addEdge(i, j + n,0x3f3f3f3f,(long long)(val -	 mat[i][j]));
			}
		}

		int a = mincost_maxflow(n+m+3);
		
		long long ans2 = C;
	
		double aux1 = ans1/100.0;
		double aux2 = ((long long)val*a - ans2)/100.0;

		printf("Problem %d: ", ++cases);
		printf("%.2lf to %.2lf\n", aux1, aux2);
	}
}
