#include<bits/stdc++.h>
using namespace std;
unsigned long long f(unsigned long long x)
{
	if(x < 10)
		return x;
	string s = to_string(x);
	unsigned long long ans = (s[0] <= s[s.size()-1] ? 1 : 0);
	return (x/10ULL - 1ULL) + ans + 9ULL;
}
int main()
{
	unsigned long long l,r;
	cin >> l >> r;
	cout << f(r) - f(l-1) << '\n';
	return 0;
}
