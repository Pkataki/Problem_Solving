#include<bits/stdc++.h>
using namespace std;
main()
{
	int r,n;
	int caso = 1;
	while(cin >> r >> n)
	{
		if(n == 0 && r == 0)
			break;
		bool ok = 0;
		for(int i = 1; i <= 27; i++)
		{
			if(n*i >= r)
			{
				ok = 1;
				cout << "Case " << caso << ": " << i-1 << '\n';
				break;
			}
		}
		if(!ok)
			cout << "Case " << caso << ": impossible\n";
		caso++;
	}
}
