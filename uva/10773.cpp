#include<bits/stdc++.h>
using namespace std;
main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		
		double d,u,v;
		cin >>d >> v >> u;
		cout << "Case " << i+1 << ": ";
		if(v >= u || v == 0 ||u == 0)
		{
			cout << "can't determine\n";
			continue;
		}
		double t1 = d/u;
		double t2 = d/(sqrt(u*u - v*v));
		if(fabs(t2-t1) == 0.0)
			cout << "can't determine\n";
		else	
			cout <<fixed << setprecision(3) <<fabs(t2-t1) << '\n';
	}
}
