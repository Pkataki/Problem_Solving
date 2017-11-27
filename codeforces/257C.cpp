#include<bits/stdc++.h>
using namespace std;
vector<double>angles;
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x,y;
		cin >> x >> y;
		double ang = atan2(x,y);
		ang = ang * 180 / acos(-1);
		if(ang < 0)
		{
			ang += 360;
		}
		angles.push_back(ang);
	}
	double ans = 0;
	sort(angles.begin(),angles.end());
	for(int i = 0; i < n-1; i++)
	{
		ans = max(ans, angles[i+1] - angles[i]);
	}
	ans = max(ans, angles.front() + 360 - angles.back());
	cout << fixed << setprecision(15) << 360 - ans << '\n';

}
