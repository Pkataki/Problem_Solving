#include<bits/stdc++.h>
using namespace std;
int n;
int mat[9][9];
int dp[(1 << 8)+1][(1 << 8)+1];
int inf;
int solve(int lin, int col)
{
	if(lin == (1 << n)-1 && col == (1 << n)-1)
		return 0;
	
	if(dp[lin][col] != inf)
		return dp[lin][col];
	
	int alice = -(1 << 28);
	for(int i = 0; i < n; i++)
	{
		if((lin & (1 << i)))
			continue;
		int bob = (1 << 28);
		for(int j = 0; j < n; j++)
		{
			if((col & (1 << j)))
				continue;
			
			bob = min(bob,solve(lin | (1 << i), col | (1 << j)) + mat[i][j]);
			
		}
		
		alice = max(alice,bob);
	}
	
	return dp[lin][col] = alice;
}
main()
{
	int test;
	cin >> test;
	while(test--)
	{
		memset(dp,0x3f3f3f,sizeof(dp));
		inf = dp[0][0];
		cin >> n;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> mat[i][j];
		
		cout << solve(0,0) << "\n";
	}
}
