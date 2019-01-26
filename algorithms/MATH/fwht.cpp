#include<bits/stdc++.h>
using namespace std;
char s[25][1 << 22];
long long cont[1 << 22];
long long ones[1 << 22];
void Fwt(long long *f, int n, int on) {
    for(int i = 2; i <= n; i <<= 1) {
        for(int j = 0; j < n; j += i) {
            for(int k = j; k < j + (i>>1); k++) {
                long long x1 = f[k], x2 = f[k+(i>>1)];
                f[k] = x1+x2;
                f[k+(i>>1)] = x1-x2;
            }
        }
    }
    if(on == -1) {
        for(int i = 0; i < n; i++) {
            f[i] /= n;
        }
    }
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n ; i++)
	{
		scanf("\n%s",s[i]);
	}
	for(int i = 0; i < m ; i++)
	{
		int mask_col = 0;
		for(int j = 0 ; j < n ; j++)
		{
			mask_col |= (s[j][i] - '0') << j ;
		}
		cont[mask_col]++;
	}
	for(int mask = 0; mask < (1 << n); mask++)
	{
		ones[mask] = __builtin_popcount(mask);
		ones[mask] = min(ones[mask] , n - ones[mask]);
	}
	Fwt(cont,1 << n, 1);
	Fwt(ones,1 << n, 1);
	for(int mask_lines = 0; mask_lines < (1 << n); mask_lines++)
	{
		cont[mask_lines] *= ones[mask_lines]; 
	}
	Fwt(cont,1 << n, -1);
	long long ans = INT_MAX;
	for(int mask_lines = 0; mask_lines < (1 << n); mask_lines++)
	{
		//cout << cont[mask_lines] << endl;
		ans = min(ans,cont[mask_lines]);
	}
	printf("%lld\n",ans);

	return 0;
}