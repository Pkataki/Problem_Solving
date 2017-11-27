#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
bool inside(double xc,double yc, double x, double y, int r)
{
	double deltax = x - xc;
	double deltay = y - yc;
	double aux = (deltax * deltax + deltay * deltay );
	return (aux <= r*r);
}
int main()
{
	int n;
	int a;	
	while(cin >> n >> a)
	{	
		if(n == 0 && a == 0)
			break;
		int m = 0;
		for(int i = 0 ; i < n ; i++)
		{
			double x,y;
			cin >> x >> y;
			if(inside(0,0,x,y,a) && inside(a,0,x,y,a) && inside(0,a,x,y,a) && inside(a,a,x,y,a) )
				m++;
		}
		cout << fixed << setprecision(5) << (double(m)*a*a/double(n)) << '\n';
	}
	return 0;
}
