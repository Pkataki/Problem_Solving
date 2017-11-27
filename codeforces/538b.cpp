#include<bits/stdc++.h>
using namespace std;
int dp[1000010], pre[1000010];
vector<int>num;
int n;
int cnt;
void Gen(int cur)
{
    if(cur <= 1000000)
    {
        num.push_back(cur);
    }
    else
        return;
    Gen(cur * 10);
    Gen(cur * 10 + 1);
}
int main()
{
    int i, j;
	num.push_back(0);
	num.push_back(1);
	Gen(1);
    sort(num.begin(),num.end());
    
	unique(num.begin(),num.end());

	cnt = num.size();
	
	cout << cnt << '\n';
	for(i = 1; i <= 1000000; i++)
    {
        for(j = 0; j < cnt; j++)
            if(i - num[j] >= 0)
            {
                if(dp[i] == 0 || dp[i - num[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - num[j]] + 1;
                    pre[i] = num[j];
                }
            }
    }
    while(~scanf("%d", &n))
    {
        printf("%d\n", dp[n]);
        while(pre[n] > 0)
        {
            printf("%d ", pre[n]);
            n -= pre[n];
        }
        puts("");
    }
    return 0;
}
