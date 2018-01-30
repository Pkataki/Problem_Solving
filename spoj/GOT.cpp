#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100105;

vector<int>graph[MAXN];

struct node
{
	int ls;
	int rs;
	int cont;
}tree[MAXN*25];
int dep[MAXN];
int v[MAXN];
int root[MAXN];

int pai[MAXN][24];

int n;
int sz;
#define getcx getchar_unlocked
#define pc(x) putchar_unlocked(x)

static int read()
{
    int c;
    while(c = getchar(), isspace(c)) {}
    int n = c - '0';
    while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
    return n;
}
 
void update(int &no, int pre, int l, int r, int pos)
{
	if(l > r)
		return;
	no = ++sz;
	tree[no] = tree[pre];
	if(l == r && pos == l)
	{
		tree[no].cont++;
		tree[no].ls = tree[no].rs = 0;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid)
		update(tree[no].ls, tree[pre].ls, l , mid, pos);
	else
		update(tree[no].rs, tree[pre].rs, mid+1 , r, pos);

	tree[no].cont = tree[tree[no].ls].cont  + tree[tree[no].rs].cont;
}

int query(int no, int l, int r, int pos)
{
	if(l > r)
		return 0;
	if(l == r && pos == l)
		return tree[no].cont;

	int mid = (l + r) >> 1;
	if(pos <= mid)
		return query(tree[no].ls,l,mid,pos);
	return query(tree[no].rs,mid+1,r,pos);
	
}

void dfs(int u, int p)
{
	pai[u][0] = p;
	update(root[u],root[p],0,n,v[u]);
	for(int i = 0 ; i < graph[u].size(); i++)
	{
		int v = graph[u][i];
		if(v == p)
				continue;
		dep[v] = dep[u] + 1;
		dfs(v,u);
	}
}
int calc()
{
	
	for(int i = 1; i <= 20 ; i++)
	{
		for(int j = 1; j <= n ; j++)
		{
			if(pai[j][i-1] != 0)
				pai[j][i] = pai[pai[j][i-1]][i-1];
		}
	}

}
int LCA(int a, int b){
    if(dep[a] < dep[b])
        swap(a, b);
    for(int i = 20; i >= 0; i --)
        if(dep[a] - (1 << i) >= dep[b])
            a = pai[a][i];
    if(a == b)
        return a;
    for(int i = 20; i >= 0; i --)
        if(pai[a][i] != -1 && pai[a][i] != pai[b][i]){
            a = pai[a][i];
            b = pai[b][i];
        }
    return pai[a][0];
}
int main()
{
	int m;
	int ca = 0; 
	while(scanf("%d %d",&n,&m) != EOF)
	{
		if(ca > 0)
			puts("");
		ca++;
		memset(root,0,sizeof(root));
		sz = 0;
		for(int i = 1; i <= n ; i++)
		{
			graph[i].clear();
			v[i] = read();
		}
		for(int i = 0 ; i < n-1 ; i++)
		{
			int u,v;
			u = read();
			v = read();
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		memset(pai,0,sizeof(pai));
		dep[0] = 0;
		dep[1] = 0;
		dfs(1,0);
		calc();
		while(m--)
		{
			int u,v,c;
			u = read();
			v = read();
			c = read();
			int lca = LCA(u,v);
			int p_lca = 0;
			if(lca == 1)
				p_lca = 0;
			else
				p_lca = pai[lca][0];
	
			int ans = query(root[u],0,n,c) + query(root[v],0,n,c) - 
			query(root[lca],0,n,c) - query(root[p_lca],0,n,c);
			// cout << lca << ' ' << p_lca << endl;;
			// cout << query(root[u],0,n,c) << endl;
			// cout << query(root[v],0,n,c) << endl;
			// cout << query(root[lca],0,n,c) << endl;
			// cout << query(root[p_lca],0,n,c) << endl; 
			if(ans > 0)
				puts("Find");
			else
				puts("NotFind");
		}
	}
	return 0;
}
