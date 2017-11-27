#include<bits/stdc++.h>
using namespace std;
main()
{
	ios::sync_with_stdio(false);
	int p,q,r,s,t,u;
	while(cin >> p >> q >> r >> s >> t >> u)
	{
		if(p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t+u>1e-9 || p+r+u<0)
		{
			cout << "No solution\n";
			continue;
		}
		double lo = 0.0;
		double hi = 1.0;
		double ref = 0.0;
		for(int it = 0; it <=50; it++)
		{
			double x = (lo+hi)/2.0;
			ref = p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
			if(ref > 0)
				lo = x;
			else
				hi = x;
		}
		cout << fixed << setprecision(4) << hi << "\n";
	}
}
