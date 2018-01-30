#include<bits/stdc++.h>
using namespace std;
const int maxn = 200;
bool vis[maxn];
int man[maxn];
int woman[maxn];
vector<int>graph[maxn];
int nx[maxn],ny[maxn];
int ty[maxn];
int dis[maxn][maxn];
int n,k;
int N;

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

int solve(int lim)
{
  for(int i = 0 ; i < N; i++)
    graph[i].clear();
  for(int i = 0 ; i < n ; i++)
  {
    for(int j = 0 ; j < n ; j++)
    {
      if(i == j)
        continue;

      if(ty[i] + ty[j] == 1 && dis[i][j] <= (lim*lim))
      {
          //cout << i << ' ' << j <<  ' ' << dis[i][j] << endl;
          graph[i].push_back(j);
      } 
    }
  }
  return maxMatch()/2;
}
int dist(int x, int y)
{
  return x*x + y*y;
}
int main()
{
  int test;
  scanf("%d",&test);
  for(int t = 1; t <= test ; t++)
  {
    
    scanf("%d %d", &n,&k);
    int cont = 0;
    for(int i  = 0 ; i < n ; i++)
    {
      char s[10];
      scanf("%d %d %s", &nx[i], &ny[i], s);
      if(!strcmp(s,"blue"))
      {
        ty[i] = 0;
      }
      else
      {
        ty[i] = 1;
        cont++;
      }
    }

    N = n;
    int hi = 10005;
    for(int i = 0 ; i < n ; i++)
    {
      for(int j = 0 ; j < n ; j++)
      {
        if(i == j)
          continue;
        dis[i][j] = dist(nx[i] - nx[j] , ny[i] - ny[j]);
       // hi = max(hi,dis[i][j]);
      }
    }
    if(min(cont, n-cont) < k)
    {
      puts("Impossible");
      continue;
    }
    int ans = 0;
    int lo = 0;
    
    while(lo <= hi)
    {
      int mid = (lo + hi) >> 1;
      int a = solve(mid);
     // cout <<  mid << " "<< a << " ** \n";
      if(a >= k)
      {
        hi = mid - 1;
        ans = mid;
      }
      else
      {
        lo = mid + 1;
      }
    }
    if(solve(ans) >= k)
      printf("%d\n",ans);
    else
      printf("Impossible\n");
  }
  return 0;
}
