#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
const int INF=0x3f3f3f3f;
int n;
int f[maxn],g[maxn],a[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1; i <=n ; i++)
        scanf("%d",&a[i]);
        
    a[0]= 0,g[n+1] = 0;
    
    for(int i=1; i<=n; i++)
        f[i] = (a[i] > a[i-1]) ? (f[i-1]+1):1;
        
    for(int i=n; i>=1; i--)
        g[i]= (a[i]<a[i+1])?(g[i+1]+1):1;
        
    int ans=-INF;
    
    for(int i=1; i<=n; i++)
    {
        if(a[i+1]-a[i-1] > 1)
        ans = max(ans , f[i-1]+g[i+1]+1);
        else
        ans = max(ans , max(g[i+1]+1,f[i-1]+1));
    }
    printf("%d\n",ans);
    return 0;
}
