#include<bits/stdc++.h>
using namespace std;

const int maxn=10000010, maxp=670000;

bool flag[maxn];
long long sum[maxn], mu[maxn], prime[maxp];

int main()
{
  mu[1] = 1;
  int tot = 0;
  for (int i = 2; i <= maxn; ++i)
  {
    if (!flag[i])
    {
      prime[tot++] = i;
      mu[i] = -1;
    }
    for (int j = 0; j < tot && i * prime[j] <= maxn; ++j)
    {
      flag[i * prime[j]] = true;
      if(!(i % prime[j]))
      {
        mu[i * prime[j]] = 0; 
        break;
      }
      else 
        mu[i * prime[j]] = -mu[i];
    }
  }
  int test;
  scanf("%d", &test);
  while(test--)
  {
    long long n;
    scanf("%lld",&n);
    long long ans = 0;
    for(long long i = 1; i * i <= n; i++)
    {
      ans += mu[i] * n/(i*i);
    }
    printf("%lld\n",ans);
  }
  return 0;
}
