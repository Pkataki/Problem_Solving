#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	cin >> n;
	long long v[n];
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v,v+n);
	
	for(int i = 2; i < n; i++)
	{
		int a = v[i-2];
		int b = v[i-1];
		int c = v[i];
		if(a + b > c && a +c > b && c + b > a)
		{
			cout << "YES\n";
			return 0;
		}
	}
	
	cout << "NO\n";
	return 0;
}
