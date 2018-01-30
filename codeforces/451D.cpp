#include<bits/stdc++.h>
using namespace std;
char s[100005];
long long contp[2], conti[2];
int main()
{
   	scanf("%s",s);
    long long sp = 0;
	long long si = 0;
	int n =strlen(s);
	for(int i = 0; i < n; i++)
    {
        int ch = s[i] - 'a';
        if((i % 2) == 0)
        {
            sp += conti[ch];
            si += contp[ch];
            contp[ch]++;
        }
        else
        {
            si += conti[ch];
            sp += contp[ch];
            conti[ch]++;   
        }
    }
	printf("%lld %lld\n",sp, n+si);
    return 0;
}
