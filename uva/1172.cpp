#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int cont1[1005][1005];
string A[1005];
string B[1005];
int valA[1005];
int valB[1005];
int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		int m;
		cin >> n;
		string s;
		for(int i = 1 ; i <= n ; i++)
			cin >> s >> A[i] >> valA[i];
		cin >> m;
		for(int i = 1 ; i <= m ; i++)
			cin >> s >> B[i] >> valB[i];
		
		memset(dp,0,sizeof(dp));
		memset(cont1,0,sizeof(cont1));
		for(int i = 1; i <= n ; i++)
		{
			for(int j = 1; j <= m ; j++)
			{
				dp[i][j] = dp[i-1][j];
				cont1[i][j] = cont1[i-1][j];
				if(dp[i][j-1] > dp[i][j] || (dp[i][j] == dp[i][j-1] && cont1[i][j] > cont1[i][j-1]))
				{
					dp[i][j] = dp[i][j-1];
					cont1[i][j] = cont1[i][j-1];	
				}
				if(A[i] == B[j])
				{
					int val = dp[i-1][j-1]  + valA[i] + valB[j];
					int cont = cont1[i-1][j-1]  + 1;
					if(val > dp[i][j] || (dp[i][j] == val && cont < cont1[i][j]))
					{
						dp[i][j] = val;
						cont1[i][j] = cont;
					}
				}
			}
		}

		cout << dp[n][m] << ' ' << cont1[n][m] << '\n';		
	}
	return 0;
}
