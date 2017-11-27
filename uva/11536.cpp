#include<bits/stdc++.h>
using namespace std;
int v[1000005];
main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n,m,k;
		cin >> n >> m >> k;

		v[1] = 1%m;	
		v[2] = 2%m;	
		v[3] = 3%m;	
		for(int i = 4; i <= n; i)
		{
			v[i] = (v[i-1] + v[i-2] + v[i-3]) % m + 1;
		}
		
	}
}
