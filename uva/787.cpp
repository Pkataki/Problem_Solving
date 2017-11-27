#include<bits/stdc++.h>
using namespace std;
int v[150];
int main()
{
	int a;
	while(1)
	{
		int n = 0;
		while(cin >> a && a != -999999)
		{
			v[n++] = a;
		}
		
		int ans = INT_MIN;
		for(int i = 0 ; i < n ; i++)
		{
			int sum = 1;
			for(int j = i; j < n; j++)
			{
				sum *= v[j];
			}
			ans = max(ans,sum);
		}
	
		cout << ans << '\n';
	}
	return 0;
}
