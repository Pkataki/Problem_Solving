#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,a,b;
	cin >> n >> a >> b;
	for(long long i = 0; i <= 10000000; i++)
	{
		if(n < i*a)
			break;
		if(((n - (i*a)) % b) == 0)
		{
			cout << "YES\n";
			cout << i << ' ' << (n - (i*a))/b << '\n';
			return 0;
		}
	}
	for(long long i = 0; i <= 10000000; i++)
	{
		if(n < i*b)
			break;
		if(((n - (i*b)) % a) == 0)
		{
			cout << "YES\n";
			cout << (n - (i*b))/a << ' ' << i  << '\n';
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}
