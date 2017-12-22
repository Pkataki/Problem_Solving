#include<bits/stdc++.h>
using namespace std;
#define max_n 2
#define MOD 1000000007
typedef struct matrix
{
	long long mat[max_n][max_n];
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
				ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % MOD;
		}
	}
	return ans;
}
matrix power(matrix base, int p)
{
	matrix ans;
	for(int i = 0; i < max_n; i++)
		for(int j = 0; j < max_n; j++)
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
main()
{	
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	matrix a;
	
	a.mat[0][0] = 1;
	a.mat[0][1] = 1;
	a.mat[1][0] = 1;
	a.mat[1][1] = 0;
	
	matrix ans = power(a,n-2);
	long long fib1 = ans.mat[0][0] + ans.mat[0][1];
	cout << fib1 << "\n";
}
