#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	int test = 1;
	while(cin >> n && n)
	{
		long long v[n];
		vector<long long> v1;
		for(int i = 0; i < n; i++)
		{
			cin >> v[i];	
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(i != j)
				{
					v1.push_back(v[i]+v[j]);	
				}
			}
		}
		sort(v1.begin(),v1.end());
		cout << "Case " << test << ":\n";
		test++;
		int q;
		cin >> q;
		while(q--)
		{
			long long a;
			cin >> a;
			int idx = lower_bound(v1.begin(),v1.end(),a) - v1.begin();
			int idx2 = upper_bound(v1.begin(),v1.end(),a) - v1.begin();
			cout << "Closest sum to " << a << " is ";
			if(abs(a - v1[idx]) == 0)
				cout << v1[idx] << ".\n";
			else if(abs(a - v1[idx-1]) <= abs(a - v1[idx2]))
				cout << v1[idx-1] << ".\n";
			else
				cout << v1[idx2] << ".\n";
		}	
	}
}
