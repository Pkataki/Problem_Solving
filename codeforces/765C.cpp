#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,a,b;
	cin >> k >> a >> b;
	int ans ;
	if((a < k && b % k != 0) || (b < k && a % k != 0))
		ans = -1;
	else
		ans = a/k + b/k;
	cout << ans << '\n';
	return 0;
}
