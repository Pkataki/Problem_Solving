#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20005;
const int MAXK = 605;
long long dp[MAXK][MAXN];
int opt[MAXK][MAXN];
long long sum[MAXN];

template<typename T>
bool read( T &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar_unlocked(); 
    if( c == EOF) { n = -1; return false; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar_unlocked(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true; 
} 
 
template<typename T>
inline void writeInt(T n){ 
    register int idx = 20; 
    if( n < 0 ) putchar_unlocked('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 

long long cost(int l, int r)
{
	if(l <= r)
  		return ((sum[r] - sum[l-1]) * (r-l+1));
	return 0LL;
}
int main()
{
	int n,k;
	cin >> n >> k;
	long long a;
	sum[0] = 0LL;
	for(int i = 1; i <= n ; i++)
	{
		cin >> a;
		sum[i] = sum[i-1] + a;	
	}
	for(int i  = 1; i <= n ; i++)
	{
		dp[i][1] = cost(1, i);
		opt[1][i] = 1;
	}
	long long aux = 0;
	for(int i = 2; i <= k ; i++)
	{
		for(int j = n; j >= 1; j--)
		{
			dp[j][i] = (1LL << 50);
			opt[n+1][i] = n;
			for(int l = opt[j][i-1]; l <= opt[j+1][i] && l+1 <= j && l <= n; l++)
			{
				aux = cost(min(l+1,j),max(j,l+1));
				if( dp[j][i] > dp[l][i-1] + aux)
				{
					dp[j][i] = dp[l][i-1] + aux;
				    opt[j][i] = l;
				}
			}
		}
	}

	cout << dp[n][k] << '\n';
	
	return 0;
}
