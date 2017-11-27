#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef struct matrix
{
	long long mat[85][85];
}matrix;
int n;
matrix mult(matrix a , matrix b)
{
	matrix ans;
	int k ; 
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(ans.mat[i][j] = k = 0; k < n; k++)
				ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]);
		}
	}
	return ans;
}
matrix power(matrix base, int p)
{
	matrix ans;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
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
	int m;
	while(cin >> n >> m && (n+m))
	{
		int v[n];
		for(int i = 0 ; i < n ; i++)
		{
			cin >> v[i];
			v[i]--;
		}
		string s;
		getchar();
		getline(cin,s);
		
		matrix t;
		memset(t.mat,0,sizeof(t.mat));
		for(int i = 0 ; i < n ; i++)
		{
			t.mat[v[i]][i] = 1;
		}
/*		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
			
				cout << t.mat[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "\n\n\n";
*/		matrix ans = power(t,m);
/*		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{	
				cout << ans.mat[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << s << " **\n";
*/		for(int i = 0; i < n; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				if(ans.mat[i][j] == 1)
				{
					cout <<	s[j];
					break;
				}
			}
		}
		cout << '\n';

	}
	return 0;
}
