#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	bool ok = 0;
	for(int i = 0; i <= n; i++)
	{
		int j = (n-4*i)/7;
		if((n-4*i) % 7 == 0 && j >= 0)
		{	
			ok = 1;
			for(int k = 0; k < i; k++)
			{
				cout << 4;
			}
			for(int k = 0; k < j; k++)
			{
				cout << 7;
			}
			break;
		}
	}
	if(!ok)
		cout << "-1\n";
	else
	cout << '\n';
	return 0;
}
