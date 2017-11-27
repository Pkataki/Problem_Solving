#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>idx;
typedef struct matrix
{
	long long mat[100][100];
}matrix;
int max_n;
int MOD;
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
			ans.mat[i][j] %= MOD;
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
int main()
{
	int n,l;
	int c = 0;
	int d[][2] = { {0,-1}, {0,1}, {1,0}, {-1,0}, {1,1} , {-1,-1}, {0,0}};
	while(cin >> n >> MOD >> l && (n+l+MOD) != 0)
	{
		int cur = 0;
		
		idx.clear();
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0; j < n + i ; j++)
			{
				idx[make_pair(i,j)] = cur++;
			}
		}
		int cur_row = n - 1;
  		int first_column = 0;
 		for (int i = n-2; i >= 0; --i)
		{
			cur_row++;
			int cur_column = ++first_column;
			for (int j = 0; j < n+i; ++j)
			{
				idx[make_pair(cur_row, cur_column)] = cur++;
				cur_column++;
			}
  		}
		matrix t;
		memset(t.mat,0,sizeof(t.mat));
		max_n = cur;
		for(auto &cell : idx)
		{
			int l = cell.first.first;
			int r = cell.first.second;
			for(int i = 0 ; i < 7 ; i++)
			{
				int dx = l + d[i][0];
				int dy = r + d[i][1];
				if(idx.count(make_pair(dx,dy)))
				{
					t.mat[cell.second][idx[make_pair(dx,dy)]]++;
				}
			}
		}
		
		int v[cur];
		for(int i = 0 ; i < cur; i++)
			cin >> v[i];
			
		matrix ans = power(t,l);

		long long ans1 = 0;
		for(int i = 0 ; i < cur; i++)
		{
			long long sum = 0;
			for(int j = 0; j < cur; j++)
			{
				sum += (ans.mat[i][j] * v[j])%MOD  ;
			}
			sum %= MOD;
			ans1 = (ans1 + sum) ;
		}
		cout <<"Case " << ++c<< ": " << ans1 << '\n';
	
	}
	return 0;
}
