  #include<bits/stdc++.h>
  using namespace std;
  const int maxn = 400005;
  vector<int>graph[maxn],rgraph[maxn];
  int comp[maxn];
  vector<int>order;
  bool used[maxn];
  int n,m;
  void dfs1(int u)
  {
    used[u] = 1;
    for(int i = 0 ; i <graph[u].size() ; i++)
    {
      int v = graph[u][i];
      if(used[v] == 0)
        dfs1(v);
    }
    order.push_back(u);
  }
  void dfs2(int u, int cl)
  {
    comp[u] = cl;
    for(int i = 0; i < rgraph[u].size() ; i++)
    {
      int v = rgraph[u][i];
      if(comp[v] == 0)
        dfs2(v,cl);
    }
  }

  bool solve()
  {
    for(int i = 0 ; i < n ; i++)
    {
      if(used[i] == 0)
        dfs1(i);
    }
    for(int i= 0, j = 0; i < n ; i++)
    {
      int v = order[n-i-1];
      if(!comp[v])
        dfs2(v,++j);
    }
    for(int i = 0 ; i < n ; i++)
    {
      if(comp[i] == comp[i^1])
        return false;
    }
    return true;
  }
  void add_edge(int x, int y)
  {
    graph[x].push_back(y);
    rgraph[y].push_back(x);
  }
  int var(int x) { return 2 * x ;}
  int neg(int x){ return x ^ 1;}
  map<int,int>mapa;
  int v[maxn];
  int main()
  {
    int a,b;
    scanf("%d %d %d",&n,&a,&b);
    for(int i = 0 ; i < n ; i++)
    {
    
      scanf("%d", &v[i]);
      mapa[v[i]] = i;
    }
   
    for(int i = 0; i < n; i++)
    {
      if(mapa.count(a - v[i]))
      {
          add_edge(var(i),var(mapa[a - v[i]]));

          add_edge(neg(var(i)),neg(var(mapa[a - v[i]])));
      }
      else
      {
          add_edge(var(i),neg(var(i)));
      }
      if(mapa.count(b - v[i]))
      {
          add_edge(var(i),var(mapa[b - v[i]]));
          add_edge(neg(var(i)),neg(var(mapa[b - v[i]])));
      }
      else
      {
          add_edge(neg(var(i)),var(i));
      } 
    }
    n = 2*n;
    if(solve())
    {
      puts("YES");
      for(int i = 0 ; i < n ; i+=2)
      {
        printf("%c ", comp[i] > comp[i ^ 1] ? '0' : '1');
      }
      puts("");
    }
    else
    {
      puts("NO");
    }
    return 0;
  }