#include<bits/stdc++.h>
using namespace std;
int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}

int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}
int main()
{
    int p,n;
    while(scanf("%d %d",&p,&n) != EOF && (n || p))
    {
        vector<int> fact;
        int phi = p-1,  m = phi;
        for (int i=2; i*i<=m; ++i)
        {
            if (m % i == 0) 
            {
                fact.push_back (i);
                while (m % i == 0)
                    m /= i;
            }
        }
        if (m > 1)
            fact.push_back (m);
        bool f = 0;
        for (int j = 0; j < n; j++)
        {
            int a;
            scanf("%d",&a);
            bool ok = 1;
            for (size_t i=0; i<fact.size() && ok; ++i)
                ok &= powmod (a, phi / fact[i], p) != 1;
            if (ok)   
                puts("YES");
            else
                puts("NO");
        }
        

    }
    return 0;
}