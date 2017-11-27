#include<bits/stdc++.h>
using namespace std;
main()
{
	int k;
	while(cin >> k)
	{
		int ans = 0;
		vector<pair<int,int> >sol;
		for(int y = k+1; y <= 2*k; y++)
		{
			if( (k*y) % ( y - k) == 0 )
			{
				int x = (k*y)/(y-k);
				sol.push_back(make_pair(x,y));		
			}
		}
		cout << sol.size() << '\n';
		for(int i = 0; i < sol.size(); i++)
		{
			cout << "1/" << k << " = 1/" << sol[i].first << " + 1/" << sol[i].second << '\n';
		}
	}
}
