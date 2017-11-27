#include<bits/stdc++.h>
using namespace std;
long long _abs(long long val)
{
	if(val < 0)
		return -val;
	return val;
}

int main()
{
	int n;
	cin >> n;
	long long v[n];
	for(int i = 0 ; i < n ; i++)
		cin >> v[i];
	long long max_total = -5555555555555;
	long long menos_atual= 0;
	long long max_atual = 0;
	for(int i = 0 ; i < n-1; i++)
	{
		long long flag = ( i % 2 == 1 ? -1:1);
		max_atual = max_atual + _abs(v[i]-v[i+1])*flag;
		menos_atual = menos_atual+ _abs(v[i]-v[i+1])*(-flag);
		max_atual = max(0LL,max_atual);
		menos_atual = max(0LL,menos_atual);
		max_total = max(max_total,max(max_atual,menos_atual));
	}
	cout << max_total << '\n';

	return 0;
}
