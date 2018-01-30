#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 10, SIZE = MAXN * 20;

struct node
{
  node *ch[26];
  int sz;
  int dp[26][110][2][2];
}aux[SIZE],*rt, *cnt;

node *newnode() 
{
  memset(cnt->dp, -1, sizeof(cnt->dp));
  memset(cnt->ch, 0, sizeof(cnt->ch));
  cnt->sz = 0; 
  return cnt++;
}

void insert(char *s)
{
  node *p = rt; 
  p->sz ++;
  for (int i = 0; s[i]; ++ i)
  {
    
    int o = s[i] - 'A';
    
    if (p->ch[o] == NULL) 
      p->ch[o] = newnode();
    
    p = p->ch[o]; 
    p->sz++;
  }

}

int solve(node *p, int c, int st, int av, bool fs, bool fa)
{
  if (!fs && !fa) 
      return 0;
  
  int &ans = p->dp[c][st][fs][fa];
  
  if (ans != -1)
    return ans;
  
  if (p->ch[c] == NULL) 
      return ans = solve(p, c + 1, st, av, fs, fa);
  
  node *q = p->ch[c]; 
  
  ans = INT_MAX;
  
  int cnt = fs * st + fa * av;
  
  if (c == 25) 
      return ans = cnt + solve(q, 0, st, av, st > 1, av > 1);
  
  for (int i = max(0, q->sz - av); i <= q->sz; i++)
  {
    

    int j = q->sz - i;

    int a = fs * i + fa * j;
    
    a += solve(q, 0, i, j, fs & (i > 1), fa & (j > 1));
    ans = min(ans, a);

    if(st < i)
        break;
    
    a += solve(p, c + 1, st - i, av - j, fs & (st > i), fa & (av > j));
    
    ans = min(ans, a);
  }
  return ans;
}

char s[MAXN];
int n;

int main()
{
    scanf("%d", &n);
    cnt = aux;
    rt = newnode();
    for (int i = 0; i < 2 * n; ++ i) {
      scanf("%s", s);
      insert(s);
    }
    int ret = solve(rt, 0, n, n, 1, 1) * n;
    printf("%d\n", ret);
  
  return 0;
}