#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	bitset<64>b = n;
	int i;
	if(n == 0)
		cout << 0 << "\n"
	else
	{
	for(long long j = 0LL; j < 64LL; j+= 1LL)
	{
		if((n&(1LL << j)) == 0)
			cont++;
	}
	int ans =cont -(__builtin_clzll(n));
	cout << (long long )(1LL << ans) << "\n";
	}
	return 0;
}
