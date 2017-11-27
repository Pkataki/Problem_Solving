#include<bits/stdc++.h>
using namespace std;
vector<long long>fact;
int main()
{
	long long n;
	cin >> n;
	if(n == 1)
	{
		cout << "1\n0\n";
		return 0;
	}
	for(long long i = 2; i * i <= n; i++)
	{
		while(n % i == 0)
		{
			fact.push_back(i);
			n/=i;
		}
	}
	if(n > 1)
		fact.push_back(n);

	if(fact.size() == 1)
	{
		cout << "1\n0\n";
	}
	else if(fact.size() == 2)
	{
		cout << "2\n";
	}
	else
		cout << "1\n" << (long long)(fact[0] * fact[1]) << '\n';
	return 0;
}
