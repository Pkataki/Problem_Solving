#include <bits/stdc++.h>
using namespace std;
struct matrix
{
	long long mat[8][8]; 
};
const int k = 8;
int mod;
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
	char a,b;
	cin >> a >> b;
	int k,p;
	cin >> k >> p;
	mod = p;
	int s = a - 'A';
	int d = b - 'A';
	matrix t;
	int mat[20][20] = {{0,1,0,1,1,0,0,0},
				   	 {1,0,1,0,0,1,0,0},
				     {0,1,0,1,0,0,1,0},
					 {1,0,1,0,0,0,0,1},
					 {1,0,0,0,0,1,0,1},
					 {0,1,0,0,1,0,1,0},
					 {0,0,1,0,0,1,0,1},
					 {0,0,0,1,1,0,1,0}};
	
	for(int i = 0; i < 8; i++)
		for(int j = 0 ; j < 8 ; j++)
			t.mat[i][j] = mat[i][j];
	
	matrix ans = power(t,k-1);
	
	for(int i = 0; i < 8; i++)
	{	
		for(int j = 0 ; j < 8 ; j++)
		{
			cout << ans.mat[i][j] << ' ';	
		}
		cout << endl;
	}
	cout << endl;
	cout  << ans.mat[s][d] << '\n';
	return 0;
}
