#include <bits/stdc++.h>
using namespace std;
int row[11];
int col[11];
int quad[11];
int mat[100][100];
int n;
int found = 0;
bool printed = 0;
void solve(int x, int y)
{
/*	bitset<10>b1 = row[x];
	bitset<10>b2 = col[y];
	bitset<10>b3 = quad[(n*(x/n)) + (y/n)];
	cout << b1 << "    " << b2 << "    " << b3 << '\n';		
	bitset<10> b = mask;
	cout <<"mask - > " << b << '\n';
*/
	int mask = row[x] | col[y] | quad[(n*(x/n)) + (y/n)];
	if((__builtin_popcount(row[x]) == (n*n)) && (__builtin_popcount(col[y]) == (n*n)) && (__builtin_popcount(quad[(n*(x/n)) + (y/n)]) == (n*n)))
	{
		return;
	}
	if(mat[x][y])
	{
		if((y == ((n*n)-1)) && ((x + 1) < (n*n)))
			solve(x+1,0);
		else if(y+1 < (n*n))
			solve(x,y+1);
		return;
	}	
	for(int i = 1; i <= n*n; i++)
	{	
		if(!(mask & (1 << i)))
		{
			row[x] |= (1 << i);
			col[y] |= (1 << i);
			
			quad[(n*(x/n)) + (y/n)] |= (1 << i);
			
			mat[x][y] = i;			
			bool can = 0;
			for(int k = 0; k < n*n; k++)
			{
				for(int j = 0; j < n*n; j++)
				{
					if(!mat[k][j])
					{
						can = 1;
					}
				}
			}
			if(!can && !printed)
			{
				printed = 1;
				found = 1;
				for(int k = 0; k < n*n; k++)
				{
					for(int j = 0; j < n*n; j++)
					{
						if(j)
							cout << ' ';
						cout << mat[k][j];
					}
					cout << '\n';
				}
			}
			if((y == ((n*n) - 1)) && (x + 1 < (n*n)))
				solve(x+1,0);
			else if(((y+1) < (n*n)))
				solve(x,y+1);
			
			mat[x][y] = 0;
			
			row[x] ^= (1 << i);
			col[y] ^= (1 << i);
			quad[(n*(x/n)) + (y/n)] ^= (1 << i);
		}
	}
}
int main()
{
	int passed = 0;
	while(cin >> n)
	{
		if(passed)
			cout << '\n';
		passed = 1;
		int a;
		for(int i = 0; i < n*n ;i++)
		{		
			for(int j = 0; j < n*n ; j++)
			{	
				cin >> mat[i][j];
				a = mat[i][j];
				
				if(a == 0)
					continue;
					
				
				quad[(n*(i/n)) + (j/n)] |= (1 << a);
				
				row[i] |= (1 << a);
				
				col[j] |= (1 << a);
			}
		}
		found = 0;
		printed = 0;
		solve(0,0);
		if(!found)
			cout << "NO SOLUTION\n";
		memset(mat,0,sizeof(mat));	
		memset(row,0,sizeof(row));	
		memset(col,0,sizeof(col));	
		memset(quad,0,sizeof(quad));	
	}
}
