#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin >> q;
	while(q--)
	{
		int n;
		cin >> n;
		int v[n];
		for(int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		bool ok = 1;
		for(int i = 0; i < n; i++)
		{
			int pos = v[i] - i;
			if(pos == 0)
			{
				continue;
			}
			else if( pos == 1)
			{
				if(abs(v[i]-v[i+1]) == 1)
					continue;
				else
					ok = 0;
			}
			else if( pos == -1)
			{
				if(abs(v[i]-v[i-1]) == 1)
					continue;
				else
					ok = 0;
			}
			else if( pos == 2)
			{
				if(abs(v[i]-v[i+1]) == 1 && abs(v[i]-v[i+2]) == 2)
					continue;
				else
					ok = 0;
			}
			else if( pos == -2)
			{
				if(abs(v[i]-v[i+1]) == 1 && abs(v[i]-v[i-2]))
					continue;
				else
					ok = 0;
			}
			else
				ok = 0;
		}
		if(ok)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
