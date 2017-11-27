#include<bits/stdc++.h>
using namespace std;
long long dp[30005];
int v[] = {1,5,10,25,50};
main()
{
	int n;
	dp[0] = 1;

	for(int i = 0; i < 5; i++)
	{
		for(int j = v[i]; j <= 30000; j++)
		{
			dp[j] += dp[j - v[i]];
		}
	}
	while(cin >> n)
	{
		if(dp[n] == 1)
			cout << "There is only 1 way to produce "  << n <<  " cents change.\n";
		else
			cout << "There are " << dp[n] << " ways to produce " << n <<  " cents change.\n";
	}
}
