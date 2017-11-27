#include<bits/stdc++.h>
using namespace std;
main()
{
	int n,k;
	while(cin >> n >> k)
	{
		cout << n + (n-1)/(k-1) << '\n';
	}
}
