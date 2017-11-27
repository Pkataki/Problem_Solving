#include<bits/stdc++.h>
using namespace std;
int v[1005];
long long C[1005][1005];
const long long MOD = 1e9 + 7;
int main()
{
	C[0][0] = 1;
	for(int i = 0; i <= 1000; i++)
	{
		C[i][0] = 1LL;
		for(int j = 1 ; j <= i; j++)
		{
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
		}
	}
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> v[i];
	int sum = 0;
	long long ans = 1;
	for(int i = 0; i < n ; i++)
	{
		ans = (ans * C[sum + v[i] - 1][v[i] - 1]) %MOD;
		sum += v[i];
	}
	cout << ans << '\n';
	return 0;
}
