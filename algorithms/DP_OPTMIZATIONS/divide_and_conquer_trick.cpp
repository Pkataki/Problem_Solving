#include<bits/stdc++.h>
using namespace std;
long long v[10004];
long long dp[605][20005];
long long pref[20005];
int n,m;
long long cost(int l, int r)
{
  return ((pref[r] - pref[l-1]) * (r-l+1));
}
void solve(int k, int lo, int hi, int opl , int opr)
{
    if(lo > hi)
        return;
    int mid = (lo + hi) >> 1;
    int opt = -1;
    dp[k][mid] = (1LL << 60);
    for(int i = opl; i <= min(mid,opr); i++)
    {
        long long aux = dp[k-1][i] + cost(i+1,mid);
        if(aux < dp[k][mid])
        {
            dp[k][mid] = aux;
            opt = i;
        }
    }
    solve(k, lo, mid-1, opl, opt);
    solve(k, mid+1, hi, opt, opr);
}
    

int main()
{
    read(n);
    read(m);
    pref[0] = 0LL;
    
    for(int i = 1; i <= n; i++)
    {
        read(v[i]);
        pref[i] = pref[i-1] + v[i];
    }
  
    for(int i = 1; i <= n; i++)
        dp[1][i] = cost(1,i);

    for(int i = 2; i <= m; i++)
        solve(i, 1, n, 1, n);
  
    printf("%lld\n",dp[m][n]);
    return 0;
}