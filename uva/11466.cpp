#include<bits/stdc++.h>
using namespace std;
main()
{
	ios_base::sync_with_stdio(0);
	int n;
	while(cin >> n && n)
	{
		int cont = 0;
		int ans = -1;
		if(n < 0)
			n *= -1;
		for(int i = 2; i*i <= n && n != 1; i++)
		{
			while(n % i == 0)
			{
				ans = i;
				n /= i;
			}
			if(ans == i)
				cont++;
		}
		if(n != 1 && ans != -1)
		{
			ans = n;
		}
		else if(cont == 1)
			ans = -1;
		
		cout << ans << '\n';
	}
}
