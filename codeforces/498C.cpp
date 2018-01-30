#include<bits/stdc++.h>
using namespace std;
const int maxn = 200;
vector<pair<int,int> > fac[maxn];
int nodes = 0;

const int maxm = 100005;
vector<bool>used(maxm);
vector<int> graph[maxm];
vector<int>mt(maxm,-1);

void factorize(int j, int a)
{
  for(int i = 2; i * i <= a; i++)
  {
    while( a % i == 0)
    {
      a /= i;
      fac[j].push_back({i,++nodes});
    }
  }
  if(a != 1)
     fac[j].push_back({a,++nodes});
}

bool kuhn(int v)
{
  if(used[v])
      return false;
  used[v] = true;
  for(auto u : graph[v])
  {
    if(mt[u] == -1 || kuhn(mt[u]))
    {
      mt[u] = v;
      return true;
    }
  }
  return false;
}
int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 1 ; i <= n ; i++)
  {
    int a;
    scanf("%d",&a);
    factorize(i,a);
  }
  while(m--)
  {
    int a,b;
    scanf("%d %d",&a,&b);
    for(auto u : fac[a])
    {
      for(auto v : fac[b])
      {
        if(u.first == v.first)
        {
          graph[v.second].push_back(u.second);
          graph[u.second].push_back(v.second);
        }
      }
    }
  }
  int ans = 0;
  for(int i = 1; i <= nodes; i++)
  {
    used.assign(maxm,0);
    if(kuhn(i))   
      ans++;
  }
  printf("%d\n",ans/2);

  return 0;
}