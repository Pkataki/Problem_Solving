#include <bits/stdc++.h>
using namespace std;
int mod;
int k;
long long c[20];
long long b[20];
long long sum[20];
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
	{
		for(int j = 0; j < k; j++)
		{
			if(i == j)
				ans.mat[i][j] = 1LL;
			else
				ans.mat[i][j] = 0LL;
		}
	}
	if(p == 0) return ans;
	if(p == 1) return base;
	while(p)
	{
		if(p & 1)
			ans = mult(ans,base);
		base = mult(base,base);
		p >>= 1;
	}
	return ans;
}

long long getsum(matrix a, int x)
{
	if(x < 0)
		return 0;
	if(x < k-1)
		return sum[x];
		
	matrix t =  power(a,x-k+2);
	
	long long ans = (t.mat[0][0] * sum[k-2]) % mod;	
	
	for(int i = 1; i < k ; i++)
	{
		ans = (ans + (t.mat[0][i] * b[k-1-i]) % mod) % mod;
	}
	return ans%mod;

}

int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	int n,m;
	cin >> test;
	while(test--)
	{
		cin >> k;
		
		for(int i = 0 ; i < k ; i++)
		{
			cin >> b[i];
		}
		for(int i = 0 ; i < k ; i++)
		{
			cin >> c[i];
		}
		cin >> m >> n >> mod;
		n--;
		m--;
		b[0] %= mod;
		sum[0] = b[0];
		for(int i = 1 ; i < k ; i++)
		{
		
			b[i] %= mod;
			sum[i] = (sum[i-1] + b[i]) %mod;
		}
		

		matrix t;
		memset(t.mat,0,sizeof(t.mat));
		
		t.mat[0][0] =1LL; 

		k++;
		
		for(int i = 1; i < k; i++)
			t.mat[0][i] = t.mat[1][i] = c[i-1];
			
		for(int i = 2 ;i < k; i++)
			t.mat[i][i-1] = 1LL;
		
		
		
		long long ans = (getsum(t,n) - getsum(t,m-1) );
		if(ans < 0)
			ans += mod;
		cout << ans << '\n';
		
	}
	return 0;
}
