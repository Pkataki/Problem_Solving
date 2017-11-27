#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	cin >> n;
	vector<int>v;
	for(int i = 2; i <= sqrt(n); i++)
	{
		if( n % i == 0)
		{
			v.push_back(i);
			v.push_back(n/i);
		}
	}
	int cont = 0;
	for(int i = 0; i < v.size()-1; i++)
	{
		for(int j = i+1 ; j < v.size(); j++)
		{
			if(__gcd(v[i],v[j]) == 1 && v[i]*v[j] == n)
				cont++;
		}
	}
	cout << cont << "\n";
}
