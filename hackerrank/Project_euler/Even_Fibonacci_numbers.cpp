#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		long long n;
		cin >> n;
		long long e1 = 0;
		long long e2 = 2;
		long long sum = 2;
		while(e2 <= n)
		{
			long long e3 = 4*e2 + e1;
			if(e3 > n)
				break;
			sum += e3;
			e1 = e2;
			e2 = e3;
		}
		cout << sum << '\n';
	}
	return 0;
}
