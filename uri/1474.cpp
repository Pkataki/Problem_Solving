#include<bits/stdc++.h>
using namespace std;
#define max_n 2
#define MOD 1000000
typedef struct matrix
{
	unsigned long long mat[max_n][max_n];
}matrix;
matrix mult(matrix a , matrix b)
{
	matrix ans;
	int k ; 
	for(int i = 0; i < max_n; i++)
	{
		for(int j = 0; j < max_n; j++)
		{
			for(ans.mat[i][j] = k = 0; k < max_n; k++)
				ans.mat[i][j] += (a.mat[i][k]%MOD * b.mat[k][j]%MOD) % MOD;
		}
	}
	return ans;
}
matrix power(matrix base, unsigned long long p)
{
	matrix ans;
	ans.mat[0][0] = 1ULL;
	ans.mat[1][1] = 1ULL;
	ans.mat[0][1] = 0ULL;
	ans.mat[1][0] = 0ULL;

	while(p)
	{
		if(p & 1ULL)
			ans = mult(ans,base);
		base = mult(base,base);
		p >>= 1ULL;
	}
	return ans;
}
//f(1) = k
//f(0) = 1
int main()
{
	unsigned long long n,k,l;
	while(cin >> n >> k >> l)
	{
		matrix a;
		a.mat[0][0] = k%MOD;
		a.mat[0][1] = l%MOD;
		a.mat[1][0] = 1ULL;
		a.mat[1][1] = 0ULL;
		
		matrix b = power(a,n/5);
		unsigned long long w = ((k%MOD)*b.mat[1][0]%MOD) + (b.mat[0][0]%MOD);
		cout << setfill('0') << setw(6) << w << '\n';
	}
	return 0;
}
