#include<bits/stdc++.h>
using namespace std;
main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int sum = 0;
		int v[n];
		
		for(int i = 0; i < n; i++)
			cin >> v[i];
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(v[j] <= v[i])
					sum++;
			}
		}
		cout << sum << '\n';
	}

}
