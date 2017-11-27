#include<bits/stdc++.h>
using namespace std;
int v[1005];
main()
{
	while(1)
	{
		int k = 0;
		int n;
		while(cin >> n && n)
		{
			v[k] = n;
			k++;
		}
		if(k == 0)
			break;
		int ans = 0;
		for(int i = 0; i < k - 1; i++)
		{
			for(int j = i +1 ; j < k; j++)
			{
				ans = __gcd(ans,abs(v[i] - v[j]));
			}
		}
		cout << ans << '\n';
	}

}
