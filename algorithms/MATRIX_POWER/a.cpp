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
			{
				ans.mat[i][j] = (ans.mat[i][j] +  (a.mat[i][k] * b.mat[k][j]) % MOD );
				ans.mat[i][j] += MOD;
				ans.mat[i][j] %= MOD;
			}	
		}
	}
	return ans;
}
matrix power(matrix base, int p)
{
	if(p == 0)
		return base; 
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
int main()
{	
	ios_base::sync_with_stdio(0);
	int x,y,n;
	cin >> x >> y >> n;
	matrix a;
	a.mat[0][0] = 1LL;
	a.mat[0][1] = -1LL;
	a.mat[1][0] = 1LL;
	a.mat[1][1] = 0LL;
	if(n == 1)
	{
		cout << (x + MOD)%MOD << '\n';
	}
	else if(n == 2)
	{
		cout << (y + MOD)%MOD << '\n';
	}
	else
	{
		matrix ans = power(a,n-2);
		long long ans1 = 0;
		ans1 = ((ans.mat[0][0] * y) % MOD + MOD)%MOD + ((ans.mat[0][1] * x) %MOD + MOD)%MOD;
		//cout << ans1 << " **\n";
		ans1 += MOD;
		ans1 %= MOD;
		cout << ans1 << '\n';
	}
	return 0;
}
