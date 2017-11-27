#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;
	int t = 1;
	while(cin >> n >> q && ((n+q) != 0))
	{
		vector<int>v(n);
		for(int i = 0 ; i < n ; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(),v.end());
		cout << "CASE# " << t << ":\n";
		t++;
		while(q--)
		{
			int a;
			cin >> a;
			int pos = lower_bound(v.begin(),v.end(),a)-v.begin();
			if(v[pos] == a)
				cout << a << " found at " << pos+1 << '\n';
			else
				cout << a << " not found\n";
		}
	}
	return 0;
}
