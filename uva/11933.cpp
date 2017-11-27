#include<bits/stdc++.h>
using namespace std;
main()
{
	unsigned int n;
	while(cin >> n && n)
	{
		unsigned int a = 0;
		unsigned int b = 0;
		for(int i = 0; i < 32; i++)
		{
			if(n & (1 << i) && (i&1))
			{
				a |= (1 << i);
			}
			else if(n & (1 << i) && !(i&1))
			{
				
				b |= (1 << i);
			}
		}
		bitset<10>b1,b2;
		b1 = a;
		b2 = b;
		cout << b1 << "    " << b2 << "\n";
		cout << a << " " << b << "\n";
	}
}
