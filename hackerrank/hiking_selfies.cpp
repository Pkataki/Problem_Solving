#include<bits/stdc++.h>
using namespace std;
unsigned long long fat[11];
int n,x;
unsigned long long comb(int val)
{
	return fat[n]/(fat[val]*fat[n-val]);
}
main()
{
	cin >> n >> x;
	fat[0]= 1ULL;
	for(int i = 1; i <= 10; i++)
		fat[i] = (unsigned long long)i*fat[i-1];
	unsigned long long ans = 0ULL;
	for(int i = 1; i <= n; i++)
		ans += comb(i);
	cout << llabs(ans - (unsigned long long)x) << "\n";
}
