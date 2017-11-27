#include<bits/stdc++.h>
using namespace std;
int mat[150][150];
int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			if(i == 0 && j == 0)
				mat[0][0] = m;
			else if(i == j)
				mat[i][j] = mat[i-1][j-1] + k;
			else if(i > j)
				mat[i][j] = mat[i-1][j] - 1;
			else if(i < j)
				mat[i][j] = mat[i][j-1]-1;
		}
	}
	for(int i  = 0; i < n ; i++)
		for(int j = 0; j < n; j++)
			cout << mat[i][j] << " \n"[j == n-1];
		
	return 0;
}

