#include<bits/stdc++.h>
using namespace std;
struct car
{
	int l,h;
	string brand;
};
main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		string a;
		int b,c;
		vector<car>autos(n);
		for(int i = 0; i < n; i++)
		{			
			cin >> autos[i].brand >> autos[i].l >> autos[i].h;
		}
		int q;
		cin >> q;
		while(q--)
		{
			int x;
			cin >> x;
			car ans; 
			int num = 0;
			for(int i = 0; i < n; i++)
			{
				if(autos[i].l <= x && x <= autos[i].h)
				{
					num++;
					ans = autos[i];
				}
			}
			if(num == 0 || num > 1)
				cout << "UNDETERMINED\n";
			else
				cout << ans.brand << '\n';
		}
		if(test)
		cout << '\n';
	}
}
