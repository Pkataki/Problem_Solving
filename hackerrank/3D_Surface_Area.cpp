#include <bits/stdc++.h>
using namespace std;
long long mat[105][105];
int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
int n,m;
bool on_limit(int i, int j)
{
	return (i < n && i >= 0 && j < m && j >= 0);	
}
int main()
{
	cin >> n >> m;
	long long sum = 0;
	for(int i= 0; i < n ; i++)
	{
		for(int j = 0; j < m ; j++)
		{
			cin >> mat[i][j];
			long long aux = (mat[i][j] * 6LL - (2LL * (mat[i][j]-2LL) + 2LL ) );
			sum += aux;
		}
	}
	for(int i = 0; i < n ; i++)
	{
		for(int j  = 0; j < m ; j++)
		{
			for(int k = 0; k < 4; k++)		
			{
				int dx = i + x[k];
				int dy = j + y[k];

				if(on_limit(dx,dy))
				{
					long long mi = min(mat[i][j],mat[dx][dy]);
					sum -= mi;
				}
			}
		}
	}
	cout << sum << '\n';
	return 0;
}
