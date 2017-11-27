#include<bits/stdc++.h>
using namespace std;
main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a,b;
		cin >> a >> b;
		for(int i = 0; i < a; i++)
		{
			int c;
			cin >> c;
			if(c > 0)
				b--;
		}
		if(b <= 0)
			cout <<	"NO\n";
		else 	
			cout << "YES\n";
	}
}
