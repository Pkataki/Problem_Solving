#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9;
int k;
long long c[15];
long long b[15];
int n;
struct matrix
{
	long long mat[20][20]; 
};
matrix mult(matrix a , matrix b1)
{
	matrix ans;
	int x;
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < k; j++)
		{
			for(ans.mat[i][j] = x = 0; x < k; x++)
				ans.mat[i][j] = (ans.mat[i][j] + (a.mat[i][x] * b1.mat[x][j]) % mod) %mod;
		}
	}
	return ans;
}
matrix power(matrix base, int p)
{
	matrix ans;
	for(int i = 0; i < k; i++)
		for(int j = 0; j < k; j++)
			ans.mat[i][j] = (i == j);
	while(p)
	{
		if(p & 1)
			ans = mult(ans,base);
		base = mult(base,base);
		p >>= 1;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	while(test--)
	{
		cin >> k;
		for(int i = 0 ; i < k ; i++)
		{
			cin >> b[i];
			b[i] %= mod;
		}
		for(int i = 0 ; i < k ; i++)
		{
			cin >> c[i];
			c[i] %= mod;
		}
		cin >> n;
		if(n <= k)
			cout << b[n-1] << '\n';
		else
		{
			matrix t;
			memset(t.mat,0,sizeof(t.mat));
			for(int i = 0; i < k; i++)
				t.mat[0][i] = c[i];
			for(int i = 1; i < k; i++)
				t.mat[i][i-1] = 1LL;
			
			matrix ans = power(t,n-k);
			
			long long ans1 = 0;
			for(int i = 0 ; i < k; i++)
			{
				ans1 = (ans1 + (ans.mat[0][i] * b[k-1-i])%mod)%mod; 
			}
			cout << ans1 << '\n';
		}
		
	}
	return 0;
}
