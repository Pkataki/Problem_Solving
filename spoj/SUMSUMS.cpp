#include<bits/stdc++.h>
using namespace std;
#define max_n 2

#define MOD 98765431
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
				ans.mat[i][j] += (((a.mat[i][k] * b.mat[k][j])% MOD )+ MOD)% MOD;
		}
	}
	return ans;
}
matrix power(matrix base, int p)
{
	matrix ans;
	for(int i = 0; i < max_n; i++)
		for(int j = 0; j < max_n; j++)
			ans.mat[i][j] = ((i == j) ? (1LL):(0LL));
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
	long long n;
	int m;
	cin >> n >> m;
	int v[n];
	long long sum = 0;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> v[i];
		sum += (long long)(v[i]);
		sum %= MOD;
	}
	matrix t;
	t.mat[0][0] = (n-1);
	t.mat[0][1] = 1LL;
	t.mat[1][0] = 0LL;
	t.mat[1][1] = -1LL;
	matrix ans = power(t,m);
	long long ans1 = (ans.mat[0][1]*sum)%MOD;
	for(int i = 0 ; i < n ; i++)
	{
		long long res;
		if(m&1)
			res = ans1-v[i];
		else
			res = ans1+v[i];
		res = ((res %MOD)+MOD)%MOD;
		cout << res << '\n';
			
	}
	return 0;
}
