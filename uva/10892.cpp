#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	while(cin >> n && n)
	{
		vector<int>div;
		for(int i = 1; i * i <= n; i++)
		{
			if(n % i == 0)
			{
				div.push_back(i);
				if( n / i != i)
					div.push_back(n/i);
			}
		}
		int ans = 0;
		for(int i = 0; i < div.size() - 1 ; i++)
		{
			for(int j = i + 1; j < div.size(); j++)
			{
				if( (div[i]* (div[j] / __gcd(div[i],div[j])))  == n)
					ans++;
			}
		}
		cout << n << " " << ans+1 << '\n';
	}
}
