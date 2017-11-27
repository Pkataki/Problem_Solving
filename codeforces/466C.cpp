#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll csum[1000010], dp[1000010][5];
ll srch[5];
int n;

ll solve(int pos, int idx)
{
    if(idx > 2) return 1;
    if(pos >= n) return 0;

    if(dp[pos][idx] != -1) return dp[pos][idx];
    ll ret = 0;
    if(csum[pos] == srch[idx])
        ret += solve(pos+1,idx+1);
    ret += solve(pos+1,idx);

    return dp[pos][idx] = ret;
}

int main()
{
    memset(dp, -1,sizeof(dp));
	scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        cin >> csum[i], csum[i] += csum[i-1];

    if(csum[n]%3)
        cout << 0 <<endl;

    else
    {
        srch[1] = csum[n]/3;
        srch[2] = 2*srch[1];
        srch[3] = 3*srch[1];
        cout << solve(1,1) << endl;
    }
    return 0;
}
