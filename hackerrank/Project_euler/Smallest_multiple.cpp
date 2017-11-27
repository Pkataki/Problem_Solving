#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b)
{
	return (a*b)/__gcd(a,b);
}
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		int _lcm = 1;
		for(int i = 3; i <= 5; i++)
		{
			_lcm = lcm(_lcm,i);
		}
		cout << _lcm << '\n';
	}
	return 0;
}
