#include <bits/stdc++.h>
using namespace std;

const int MAXN1 = 500;
const int MAXN2 = 500;
const int MAXM = 150000;

int n1, n2, edges, last[MAXN1], pre[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void add_edge(int u, int v) {
    head[edges] = v;
    pre[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = pre[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = pre[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}
bool used1[MAXN1];
int main()
{
	ios_base::sync_with_stdio(0);
	int N,q;
	while(cin >> N >> q)
	{

		set<int>parent[110];
		for(int i = 0; i < N ; i++)
		{
			int a;
			cin >> a;
			for(int j = 0; j < a; j++)
			{
				int b;
				cin >> b;
				parent[i].insert(b);
			}
			if(a < N)
				parent[i].insert(0);
		}
		for(int i = 0; i < q; i++)
		{
	
			int a;
			cin >> a;
			init(N+1,N+1);
			//cout << "\n\nNOVA QUERY\n\n\n\n\n\n";
			
			memset(used1,0,sizeof(used1));
			for(int j = 0; j < a; j++)
			{
				int b;
				cin >> b;
				for(int k = 0; k < N; k++)
				{
					if(parent[k].count(b))
					{
						//cout << "liguei o pai: " << k << " com o alelo: " << b << endl;
						add_edge(k,b);
						used1[k] = 1;
					}
				}				
			}
			int cont = 0;
			for(int j = 0 ; j < N; j++)
			{
				if(parent[j].count(0) && a != N)
					used1[j] = 1;
				cont+= used1[j];
			}
			if(cont < N)
			{
				//cout << "nao usei todos os pais\n";
				cout << "N\n";
				continue;
			}
			int ans = maxMatching();
			//cout << "O FLUXO É " << ans << endl;
			if(ans == a)
				cout << "Y\n";
			else
				cout << "N\n";
		}
	}
	return 0; 
}
