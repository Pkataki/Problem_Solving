#include<bits/stdc++.h>
using namespace std;
int v[7];
int main()
{	
	int x,y,z,x1,y1,z1;
	cin >> x >> y >> z >> x1 >> y1 >> z1;
	for(int i = 1; i <= 6; i++)
		cin >> v[i];
	int ans = 0;
	ans += (y < 0 ? v[1] : 0);
	ans += (y > y1 ? v[2] : 0);
	ans += (x < 0 ? v[5] : 0);
	ans += (x > x1 ? v[6] : 0);
	ans += (z < 0 ? v[3] : 0);
	ans += (z > z1 ? v[4] : 0);
	cout << ans << '\n';
	return 0;
}
