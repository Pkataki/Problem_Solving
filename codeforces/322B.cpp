#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r,g,b;
	cin >> r >>g >> b;
	bool has =0;
	int ans= 0;
	for(int bq = 0; bq < 3; bq++)
	{
		if(bq <= min(r,min(g,b)))
		{
			int sum = bq;
			int r1 = r-bq;
			int g1 = g-bq;
			int b1 = b-bq;
			sum += (r1/3) + (g1/3) + (b1/3);
			ans = max(ans,sum);
		}
	}
	cout << ans << '\n';
}
