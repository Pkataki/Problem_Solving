#include<bits/stdc++.h>
using namespace std;
main()
{
	long long n;
	while(cin >> n && n)
	{
		cout << n << " =";
		bool hf = 0;
		if(n < 0LL)
		{
			hf = 1;
			cout << " -1";
			n *= -1LL;
		}
		bool f = 1;	
		for(int i = 2; i <= sqrt(n); i++)
		{
			while(n % i ==0)
			{
				if(f && !hf)	
					cout << " " << i;
				else
					cout << " x " << i;
				n /= i; 
				f = 0;
			}
		}
		if(n > 1 && !hf && f)
			cout << " " << n << "\n";
		else if(n > 1 && ( hf || !f))
			cout << " x " << n << "\n";
		else
			cout << "\n";
	}
}
