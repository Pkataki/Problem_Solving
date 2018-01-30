#include <bits/stdc++.h>
#define LL long long
#define lc (x << 1)
#define rc (x << 1 | 1)
#define INF 0x7FFFFFFF
using namespace std;

template<class T> inline
void read(T& x) {
    int f = 1; x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')   {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

/*============ Header Template ============*/

const int N = 100000 + 5;

int n, m;
int vis[N << 1];
char op[100];

struct line {
    long long k, b;
    line(long long _k = 0, long long _b = 0) {
        k = _k; b = _b;
    }
    long long get(long long x) {
        return k * x + b;
    }
} c[N << 1];

void modify(int x, int l, int r, line v) {
    if (!vis[x])
    {
        vis[x] = 1; 
        c[x] = v; 
        return;
    }
    if (c[x].get(l) > v.get(l) && c[x].get(r) > v.get(r)) 
        return;
    if (c[x].get(l) < v.get(l) && c[x].get(r) < v.get(r))
    {
        c[x] = v; 
        return;
    }
    int m = (l + r) >> 1;
    if (c[x].get(l) < v.get(l)) 
        swap(c[x], v);
    if (c[x].get(m) > v.get(m)) 
        modify(rc, m + 1, r, v);
    else
    {
        swap(c[x], v); 
        modify(lc, l, m, v);
    }
}

long long get(int x, int l, int r, int pos) {
    if(l > r)
        return -(1LL << 60);
    if (l == r) 
        return c[x].get(l);
    int m = (l + r) >> 1; 
    long long ans = c[x].get(pos);
    if (pos <= m) 
        ans = max(ans, get(lc, l, m, pos));
    else 
        ans = max(ans, get(rc, m + 1, r, pos));
    return ans;
}
/*
int main() {
    read(n);
    double k, b;
    for (int i = 1, x; i <= n; i++) {
        scanf("%s", op);
        if (op[0] == 'Q') {
            read(x);
            printf("%lf\n", get(1, 1, n, x));
        } else {
            scanf("%lf%lf", &k, &b);
            line l = line(k, b);
            modify(1, 1, n, l);
        }
    }
    return 0;
}*/
long long a[1000006];
long long  d[1000006];
int main()
{
    int n;
    scanf("%d",&n);
    line l = line(0,0);
    modify(1,0,n,l);
        
    for(int i = 0; i < n ; i++)
    {
        scanf("%lld %lld",&a[i],&d[i]);
    }
   // ans.insert(0LL,0LL);
    for(int i = 0; i < n ; i++)
    {   
        long long m = get(1, 0, n, i) + a[i];
        //cout << ans.query(i) << ' ' << a[i] << " **\n";
        long long nn = m + (i) * d[i]; 
        //cout << nn << '\n';
        line l = line(-d[i],nn);
        modify(1,0,n,l);
    }
    printf("%lld\n",get(1, 0, n, n));
    return 0;
}