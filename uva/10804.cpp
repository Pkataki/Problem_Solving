#include<bits/stdc++.h>
using namespace std;
const int maxn = 200;
bool vis[maxn];
int man[maxn];
int woman[maxn];
vector<int>graph[maxn];
int nv;
double mx[60],my[60],nx[60],ny[60];
double dis[55][55];
const double EPS = 1e-9;
int n,m,k;
int N;
int cmp(double a, double b)
{
  if(fabs(a - b) < EPS)
    return 0;
  return a < b ? -1 : 1;
}
bool match(int manIndex) {
  for (int i = 0; i < graph[manIndex].size(); i++) {
    int curwoman = graph[manIndex][i];
    if (vis[curwoman])
      continue;
    vis[curwoman] = true;
    if (woman[curwoman] == -1 || match(woman[curwoman])) {
      man[manIndex] = curwoman;
      woman[curwoman] = manIndex;
      return true;
    }
  }
  return false;
}
int maxMatch() {
  int cnt = 0;
  memset(man, -1, sizeof man);
  memset(woman, -1, sizeof woman);
  for (int i = 0; i < N; i++)
    if (man[i] == -1) {
      memset(vis, 0, sizeof vis);
      if (match(i))
        cnt++;
    }
  return cnt;
}

int solve(double lim)
{
  for(int i = 0 ; i < N; i++)
    graph[i].clear();
  for(int i = 0 ; i < n ; i++)
  {
    for(int j = 0 ; j < m ; j++)
    {
      if(dis[i][j] < lim)
      {
          graph[i].push_back(j);
      } 
    }
  }
  return maxMatch();
}
double dist(double x, double y)
{
  return hypot(x,y);
}
int main()
{
  int test;
  scanf("%d",&test);
  for(int t = 1; t<= test ; t++)
  {
    
    scanf("%d %d %d", &n,&m,&k);
    for(int i  = 0 ; i < m ; i++)
    {
      scanf("%lf %lf", &mx[i], &my[i]);
    }
    for(int i  = 0 ; i < n ; i++)
    {
      scanf("%lf %lf", &nx[i], &ny[i]);
    }

    double lo  = 0, hi = 0.0;
    N = n;
    for(int i = 0 ; i < n ; i++)
    {
      for(int j = 0 ; j < m ; j++)
      {
        dis[i][j] = dist(nx[i] - mx[j] , ny[i] - my[j]);
        hi = max(hi,dis[i][j]);
      }
    }
    double ans;
    for(int cont = 0; cont <= 300; cont++)
    {
      double mid = (lo + hi)/2.0;
      int a = solve(mid);
    //  cout << a << " ** \n";
      if(a >= n-k)
      {
        hi = mid ;
        ans = mid;
      }
      else
      {
        lo = mid ;
      }
    }
    printf("Case #%d:\n",t);
    if(solve(ans) >= n-k)
      printf("%.3lf\n\n",ans);
    else
      printf("Too bad.\n\n");
  }
  return 0;
}
