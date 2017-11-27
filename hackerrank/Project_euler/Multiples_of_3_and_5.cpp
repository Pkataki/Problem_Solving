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
		long long aux = (n-1)/3;
		long long aux1 = (n -1)/5;
		long long aux2 = (n -1)/15;
		long long ans = (aux * (aux+1) * 3) /2;
		long long ans1 = (aux1 * (aux1+1) * 5)/2;
		long long ans2 = (aux2 * (aux2+1) * 15)/2;
		cout << (ans + ans1)  - ans2<< '\n'; 
	}
	return 0;
}
