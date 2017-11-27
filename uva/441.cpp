#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>v;
void backtrack(int mask, int pos)
{
	if(__builtin_popcount(mask) == 6)
	{
		int cont = 0;
		for(int i = 0; i < n; i++)
		{
			if(mask & (1 << i))
			{
				cont++;
				cout << v[i];
			
				if(cont < 6)
					cout << ' ';
			}
		}
		cout << '\n';
		return;
	}
	for(int i = pos+1; i < n; i++)
	{
		backtrack(mask |(1 << i), i);
	}
}
main()
{
	bool jump = 0;
	while(cin >> n && n)
	{
		if(jump)
			cout << '\n';
		v.clear();
		for(int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		backtrack(0,-1);
		jump = true;
	}
}
