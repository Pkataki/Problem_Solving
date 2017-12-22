#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		unsigned long long a;
		cin >> a;
		int cont = 0;
		int ans = 0;
		while(a)
		{	
			if(a & 1)
				cont++;
			else
			{
				ans = max(ans,cont);
				cont = 0;
			}
			a >>= 1;
		}
		ans = max(ans,cont);
		cout << ans << '\n';
	}
	return 0;
}
