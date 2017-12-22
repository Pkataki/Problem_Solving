#include<bits/stdc++.h>
using namespace std;
string v[60];
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		int m;
		cin >> m;
		for(int j = 0; j < m ; j++)
		{
			string a;
			cin >> a;
			bool ok = 1;
			for(int i = 0; i < n ; i++)
			{
				size_t k = a.find(v[i]);

				if(k != string::npos)
				{
					if(v[i].size() + k >= a.size())
					{
						ok = 0;
						cout << "Abortar\n";
						break;
					}
					else if(a[k+v[i].size()+1] >= 'a' && a[k+v[i].size()+1] <= 'z' )
					{
						ok = 0;
						cout << "Abortar\n";
						break;
					}
				}
			}
			if(ok)
				cout << "Prossiga\n";
		}
		if(test)
			cout << '\n';
	}
	return 0;
}
