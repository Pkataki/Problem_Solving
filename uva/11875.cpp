#include<bits/stdc++.h>
using namespace std;
main()
{	
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int caso = 1; caso <= t; caso++)
	{
		int n;
		cin >> n;
		int v[n];
		for(int i = 0; i < n ; i++)
			cin >> v[i];
		sort(v,v+n);
		cout << "Case " << caso << ": " << v[n/2] << '\n';
	}
}


