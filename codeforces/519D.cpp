#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 100000 + 5;
int A[N];
LL sum[N];
char str[N];
int value[26];
int n;

int main() 
{
    for (int i = 0; i < 26; ++ i)
	{
        scanf("%d",&value[i]);
    }
    scanf("%s",str+1);
    n = strlen(str+1);
    for (int i = 1; i <= n; ++ i)
	{
        sum[i] = sum[i-1] + value[str[i] - 'a'];
    }
    map<LL,LL> map[26];
    LL ans = 0;
    for (int i = 1; i <= n; ++ i)
	{
        int c = str[i] - 'a';
        ans += map[c][sum[i-1]];
        map[c][sum[i]]++;
    }
    printf("%I64d\n",ans);
}
