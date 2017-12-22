#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
long long dp[100][100][100];
int la,lb;
ull v[60];
int n,k;
const int tab64[64] = {
    63,  0, 58,  1, 59, 47, 53,  2,
    60, 39, 48, 27, 54, 33, 42,  3,
    61, 51, 37, 40, 49, 18, 28, 20,
    55, 30, 34, 11, 43, 14, 22,  4,
    62, 57, 46, 52, 38, 26, 32, 41,
    50, 36, 17, 19, 29, 10, 13, 21,
    56, 45, 25, 31, 35, 16,  9, 12,
    44, 24, 15,  8, 23,  7,  6,  5};

int log2_64 (uint64_t value)
{
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    value |= value >> 32;
    return tab64[((uint64_t)((value - (value >> 1))*0x07EDD5E59A4E28C2)) >> 58];
}
long long solve(int pos, int q, ull sum)
{
	if(q == 0)
	{
		cout << q << ' ' << sum << ' ' << log2_64(sum) << endl;
		if(log2_64(sum) >= la && log2_64(sum) <= lb)
			return 1;
		return 0;
	}
	if(pos == n)
			return 0;

	long long &ans = dp[pos][log2_64(sum)][q];
	if(ans != -1LL)
			return ans;
	ans = 0;
	ull aux = sum + v[pos];
	ans += solve(pos+1, q-1, aux) +solve(pos+1, q, sum);
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	int test;
	cin >> test;
	while(test--)
	{
		memset(dp,-1,sizeof(dp));
		cin >> n >> k;
		ull a,b;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> v[i];
		}
		sort(v,v+n);
		cin >> a >> b;
		la = log2_64(a);
		lb = log2_64(b);
		cout << solve(0,k,0ULL) << '\n';
	}
	return 0;
}
