#include <bits/stdc++.h>
using namespace std;
int main()
{
	int mat[3][3];
	int sum = 0;
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			cin >> mat[i][j];
			sum += mat[i][j];
		}
	}
	int val = sum/2;
	mat[0][0] = val -  (mat[0][1] + mat[0][2]);
	mat[1][1] = val -  (mat[1][0] + mat[1][2]);
	mat[2][2] = val -  (mat[2][0] + mat[2][1]);
	for(int i = 0; i < 3 ; i++)
	{
		for(int j   = 0 ; j < 3 ; j++)
			cout << mat[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
