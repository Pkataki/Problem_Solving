#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4005;
const int MAXK = 805;
int dp[MAXK][MAXN];
int opt[MAXK][MAXN];
int mat[MAXN][MAXN], sum[MAXN][MAXN];

/*
    DIVIDE AND CONQUER TRICK
    DP[I][J] = MIN(K | DP[I-1][K] + COST(K+1, J))
    PRIMEIRO ESTADO É A QUANTIDADE DE GONDOLAS USADAS
    SEGUNDO ESTADO É A QUANTIDADE DE CARAS QUE TO COLOCANDO NOS I GRUPOS ATUAIS,
    OU SEJA 1...J CARAS, QUERO ENCONTRAR O MENOR K QUE DP[I-1][K] + COST(K+1, J)
    SEJA OTIMO.
    A[I][J] <= A[I][J+1] É MONOTONO;
*/

bool read( int &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar(); 
    if( c == EOF) { n = -1; return false; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true; 
} 
 
inline void writeInt(int n){ 
    register int idx = 20; 
    if( n < 0 ) putchar('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar(out[idx++]); } while (out[idx] != ' '); 
} 
 

inline int cost(int a, int b){
  return (sum[b][b] - sum[a - 1][b] - sum[b][a - 1] + sum[a - 1][a - 1]) / 2;
}

void divide_and_conquer(int num_groups, int lo, int hi, int from ,int to)
{
    if(lo > hi)
        return;
    int mid = (lo + hi) >> 1;
    for(int j = from; j <= to && j <= mid; j++)
    {
        int val = dp[num_groups - 1][j] + cost(j+1,mid);
        if(dp[num_groups][mid] > val)
        {
            dp[num_groups][mid] = val;
            opt[num_groups][mid] = j;
        }
    }
    divide_and_conquer(num_groups, lo   , mid-1 , from , opt[num_groups][mid]);
    divide_and_conquer(num_groups, mid+1, hi    , opt[num_groups][mid], to);
}

int main()
{
    int n,k;
    read(n);
    read(k);
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= n ; j++)
        {
            read(mat[i][j]);
        }
    }
     for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            sum[i][j] = mat[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];


    for(int i = 0; i<= k; i++)
        for(int j = 0; j <= n ; j++)
            dp[i][j] = (1 << 30);

    for(int i = 1; i <= n; i++)
    {
        dp[1][i] = cost(1,i);
    }

   for(int i = 2; i <= k; i++)
    divide_and_conquer(i, 1, n, 1, n);

    writeInt(dp[k][n]);
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
long long v[10004];
long long dp[605][20005];
long long pref[20005];
int n,m;
long long cost(int l, int r)
{
  return ((pref[r] - pref[l-1]) * (r-l+1));
}
void solve(int k, int lo, int hi, int opl , int opr)
{
	if(lo > hi)
		return;
	int mid = (lo + hi) >> 1;
	int opt = -1;
	dp[k][mid] = (1LL << 60);
	for(int i = opl; i <= min(mid,opr); i++)
	{
		long long aux = dp[k-1][i] + cost(i+1,mid);
		if(aux < dp[k][mid])
		{
			dp[k][mid] = aux;
			opt = i;
		}
	}
	solve(k, lo, mid-1, opl, opt);
	solve(k, mid+1, hi, opt, opr);
}
	
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

int main()
{
	read(n);
	read(m);
	pref[0] = 0LL;
	
	for(int i = 1; i <= n; i++)
	{
		read(v[i]);
		pref[i] = pref[i-1] + v[i];
	}

    
    for(int i = 1; i <= n; i++)
		dp[1][i] = cost(1,i);
	
	

   	for(int i = 2; i <= m; i++)
    	solve(i, 1, n, 1, n);


	
	printf("%lld\n",dp[m][n]);
	return 0;
}
*/
