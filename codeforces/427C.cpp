#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int MAXN = 100005;
int cost[100010];
vector<int> g[MAXN];
int d[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc;
void tarjan(int u){
  d[u] = low[u] = ticks++;
  s.push(u);
  stacked[u] = true;
  const vector<int> &out = g[u];
  for (int k=0, m=out.size(); k<m; ++k){
    const int &v = out[k];
    if (d[v] == -1){
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }else if (stacked[v]){
      low[u] = min(low[u], low[v]);
    }
  }
  if (d[u] == low[u]){
    int v;
    do{
      v = s.top();
      s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
    }while (u != v);
    current_scc++;
  }
}
int mini[100005];
int cont[100005];
int main()
{
	memset(d,-1,sizeof(d));
	memset(low,0,sizeof(low));
	memset(scc,-1,sizeof(scc));
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&cost[i]);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		g[a].push_back(b);
	}
	for(int i = 1; i <= n; i++)
	{
		if(d[i] == -1)
		{	
			tarjan(i);
		}
	}
	for(int i = 0; i < current_scc; i++)
	{
		mini[i] = (1 << 30); 
	}
	for(int i = 1; i <= n; i++)
	{
		int c = cost[i];
		int comp = scc[i];
		if(mini[comp] > c)
		{
			mini[comp] = c;
			cont[comp] = 1;
		}
		else if(mini[comp] == c)
			cont[comp]++;
	}
	long long a = 0;
	long long b = 1;
	for(int i = 0; i < current_scc; i++)
	{
		a += (long long)mini[i];	
		b *= (long long)cont[i];
		b %= (long long)mod;
	}
	printf("%lld %lld\n",a,b);
}
