#include<bits/stdc++.h>
using namespace std;
int dp[1010][50][90];
int mat[1010][3];
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int nit,oxi;
		cin >> nit >> oxi;
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < 3; j++)
				cin >> mat[i][j];
		}
	
		
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0 ; j <= 21; j++)
			{
				for(int k = 0; k <= 79; k++)
				{
					if(!i)
					{
						dp[0][j][k] = 1 - ~(1 << 29);
						if(!j && !k)
							dp[0][0][0] = 0;
					}
					else
					{
						dp[i][j][k] = min(dp[i-1][j][k] , dp[i-1][max(0,j-mat[i][0])][max(0,k-mat[i][1])] + mat[i][2]);
					}
				}
			}
		}
		cout << dp[n][nit][oxi] << '\n';
	}
}
