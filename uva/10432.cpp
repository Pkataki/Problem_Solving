#include<bits/stdc++.h>
using namespace std;
int main()
{
	double r;
	int n;
	while(cin >> r >> n)
	{
		double phi = 360.0/n;
		double theta = 90.0 - phi/2.0;
		theta = theta *M_PI / 180.0;
		double a = 2*r*cos(theta);
		double h = r*sin(theta);
		cout << fixed << setprecision(3) << a*h/2 * n << '\n';
	}
	return 0;
}
