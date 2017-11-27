#include<bits/stdc++.h>
using namespace std;
int max_n;
#define MOD 4242
typedef struct matrix
{
	long long mat[(1 << 7)][(1 << 7)];
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
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n,c;
		cin >> n >> c;
		string s;
		cin >> s;
		max_n = (1 << c);
		int cant_go_before[c] = {0};
		for(int letter = 0; letter < c; letter++)
		{
			int pos = s.size()-1;
			while(pos && (s[pos]-'A' != letter))
				pos--;
			//pos--;
			while(pos > 0)
			{
				pos--;
				cant_go_before[letter] |= (1 << s[pos] - 'A');
			}
			
		}
		matrix t;
		memset(t.mat,0,sizeof(t.mat));
		for(int mask = 0; mask < (1 << c); mask++)
		{
			for(int letter = 0; letter < c; letter++)
			{
				if(mask & (1 << letter))
				{
					if( !(cant_go_before[letter] & mask) )
					{
						t.mat[mask][mask]++;
					}
				
					int prev = mask ^ (1 << letter);
				
					
					if( !(cant_go_before[letter] & prev) )
					{
						t.mat[prev][mask]++;
					}
					
				}
			}
		}
		matrix ans = power(t,n);
		
		long long ans1 = 0;
		for(int i = 0; i < (1 << c); i++)
		{
			ans1 = (ans1 + ans.mat[0][i]) % MOD;
		}
		cout << ans1 << '\n';
	}
	return 0;
}
