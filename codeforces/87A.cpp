#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b;
	cin >> a >> b;
	long long g = (b/__gcd(a,b)) * a;
	long long x = g / a;
	long long y = g / b;
	if(abs(x-y) == 1)
		cout << "Equal\n";
	else if(x < y)
		cout << "Masha\n";
	else
		cout << "Dasha\n";
	return 0;
}
