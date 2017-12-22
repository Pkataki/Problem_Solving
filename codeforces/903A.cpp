#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a,b;
		cin >> a;
		bool ok = 0;
		for(int i = 0; i <= 100; i++)
		{
			for(int j = 0; j <= 100 ; j++)
			{
				if( i*3 + 7*j == a)
				{
					ok = 1;
					break;
				}
			}
		}
		if(ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
