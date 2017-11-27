#include<bits/stdc++.h>
using namespace std;
bitset<26>awake;
vector<vector<int> >v(26);
int n,m;
string s;
main()
{
fim:
	while(cin >> n >> m)
	{
		getline(cin,s);
		fill(v.begin(),v.end(),vector<int>());
		awake.reset();
		for(int i = 0; s[i]; i++)
		{
			awake.set(s[i] - 'A');
		}
		for(int i = 0; i < m; i++)
		{
			getline(cin,s);
			int a = s[0] - 'A';
			int b = s[1] - 'A';
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int y = 0;
		bool end = 0;
		while(awake.count() < n)
		{
			vector<int>wokeup;
			for(int i = 0; i < 26; i++)
			{
				if(awake[i])
					continue;
				int awake_nei = 0;
				for(int j = 0; j < v[i].size(); j++)
				{
					if(awake[v[i][j]])
						awake_nei++;
				}
				if(awake_nei >= 3)
					wokeup.push_back(i);
			}
			if(wokeup.empty())
			{
				cout << "THIS BRAIN NEVER WAKES UP\n";
				goto fim;
			}
			for(int i = 0; i < wokeup.size(); i++)
				awake.set(i);

			y++;
			
		}
		cout << "WAKE UP IN, " << y << ", YEARS\n";
	}
}
