#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	cin >> n;
	int a = 0;
	long long ans = 0;
	if(n % 10 >= 5)
		n += 10;
	ans = n/10LL;
	cout << ans *10LL << '\n';
	return 0;
}
