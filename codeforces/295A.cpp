#include <bits/stdc++.h>

const int N = 100005;

long long l[N];
long long r[N];
long long d[N];
long long a[N];
long long op[N];
long long b[N];

main()
{

    long long n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
        
    for (int i = 1; i <=  m; ++i)
        scanf("%lld%lld%lld", &l[i], &r[i], &d[i]);
        
    long long x, y;
    for (int i = 1; i <= k; ++i)
    {
        scanf("%lld%lld", &x, &y);
        ++op[x];
        --op[y+1];
    }
    for (int i = 1; i <= m; ++i)
    {
        op[i] += op[i - 1];
        d[i] *= op[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        b[l[i]] += d[i];
        b[r[i]+1] -= d[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        b[i] += b[i - 1];
        a[i] += b[i];
    }
    printf("%lld", a[1]);
    for (int i = 2; i <= n; ++i)
        printf(" %lld", a[i]);
}
