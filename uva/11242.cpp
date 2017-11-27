#include<bits/stdc++.h>
using namespace std;
main()
{
	int f,r;
	while(cin >> f && f)
	{
		cin >> r;
		int fc[f];
		int rc[r];
		
		for(int i = 0; i < f; i++)
			cin >> fc[i];
		
		for(int i = 0; i < r; i++)
			cin >> rc[i];
		
		double ratio[100];
		
		int idx = 0;
		
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < f; j++)
			{
				ratio[idx]	= (double)rc[i] / (double)fc[j];
				idx++;
			}
		}
		
		sort(ratio,ratio+idx);
		
		double ans = -1;
		for(int i = 0; i < idx-1; i++)
		{
			ans = max(ans,ratio[i+1]/ratio[i]);
		}
		cout << fixed << setprecision(2) << ans << '\n';
	}
	
}
