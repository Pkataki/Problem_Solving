#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int a[MAXN];
int out[MAXN];
int lv[MAXN];
int v[MAXN];
int in[MAXN];
vector<int>graph[MAXN];
int cont = 1;
long long bit[2][MAXN];
void update(int ib, int idx, long long val)
{
	while(idx < MAXN)
	{
		bit[ib][idx] += val;
		idx += (idx & (-idx));
	}
}
long long query(int ib, int idx)
{
	long long ans = 0;
	while(idx > 0)
	{
		ans += bit[ib][idx];
		idx -= (idx & (-idx));
	}
	return ans;
}

void dfs(int x, int pai)
{
	v[x] = cont;
	in[x] = cont;
	lv[x] = (lv[pai] + 1) % 2;
	for(int i = 0 ; i < graph[x].size(); i++)
	{
		int u = graph[x][i];
		if(u == pai)
			continue;
		cont++;
		dfs(u,x);
	}
	out[x] = cont;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	for(int i = 1; i < n ; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	lv[1] = 0;
	dfs(1,1);
	while(m--)
	{
		int op;
		scanf("%d",&op);
		if(op == 1)
		{
			int x,val;
			scanf("%d %d", &x,&val);
			update(lv[x],in[x],val);
			update(lv[x],out[x]+1,-val);

			update(!lv[x],in[x],-val);
			update(!lv[x],out[x]+1,val);
		}
		else
		{
			int x;
			scanf("%d",&x);
			printf("%lld\n",a[x] + query(lv[x],v[x]));
		}
	}
	return 0;
}
