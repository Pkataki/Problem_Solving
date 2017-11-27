#include<bits/stdc++.h>
using namespace std;
int cont = 0;
long long gcd(long long x, long long y)
{
	if (x == 0) return 0;
	if (y == 0) return 0;
	return gcd(y, x%y) + x/y;
}
int main()
{
	long long a,b;
	cin >> a >> b;
	if(a < b)
		swap(a,b);
	cout << gcd(a,b) << '\n';
	return 0;
}
