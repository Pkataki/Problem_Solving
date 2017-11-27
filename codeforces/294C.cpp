#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD 1000000007
using namespace std;
LL n,m,C[1001][1001],ans=1,s[1001],poww[1001];
int main()
{
    cin >> n >> m;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0;j <= i; j++)
        {
            if(j == 0 || j == i) 
            	C[i][j]=1;
            else 
            	C[i][j]=(C[i-1][j-1]+C[i-1][j])% MOD;
        }
    }
    poww[0] = 1;
    poww[1] = 1;
    for(int i = 2;i <= n; i++) 
    	poww[i] = (poww[i-1] * 2)% MOD;
    for(int i = 0;i < m; i++) 
    	cin >> s[i];
    sort(s,s+m);
    LL tot = 0,sz;
    for(int i = 0; i < m;   i++)
    {
        if(i == 0) 
        	sz = s[i]-1;
        else
        {
            sz = s[i]-s[i-1]-1;
            ans = (ans*poww[sz])% MOD;
        }
        tot += sz;
        ans = (ans * C[tot][sz]) % MOD;
    }
    tot += n - s[m-1];
    ans = ans * C[tot][n-s[m-1]] % MOD;
    cout << ans << endl;
    return 0;
}
