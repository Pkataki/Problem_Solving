#include<bits/stdc++.h>
using namespace std;
int phi(int n)
{
	int ans= n;
	for(int i = 2; i * i <= n; i++)
	{
		if(n%i == 0)
		{
			ans -= ans / i;
			
			while(n%i == 0)
				n /= i;
		}
	}
	if(n > 1)
		ans -= ans/n;
	return ans;
}

main()
{
	ios_base::sync_with_stdio(0);
	int n;
	while(cin >> n && n)
	{
		if(n == 1)
			cout << "0\n";
		else
			cout << phi(n) << '\n';	
	}
}
