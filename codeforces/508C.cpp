#include<bits/stdc++.h>
using namespace std;
int n,m,t,r,ans,p;
int a[2000],candle[2000];

int main()
{
    cin >> m >> t >> r;
    for(int i = 0; i < m; i++)
        scanf("%d",&a[i]);
    if(t < r)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i = 0; i < r; i++)
        candle[i] = -1000;
    ans = 0;
    for(int i = 0; i < m; i++)
    {
        p = 0;
        for(int j = 0; j < r; j++)
        {
            if (candle[j] + t < a[i])
            {
                p++;
                candle[j] = a[i] - p;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
} 
