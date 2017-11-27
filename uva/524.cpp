#include<bits/stdc++.h>
using namespace std;
bool isprime[32];
main()
{
	isprime[2] = isprime[3] = isprime[5] = 1;
	isprime[7] = isprime[11] = isprime[13] = 1;
	isprime[17] = isprime[19] = isprime[23] = 1;
	isprime[29] = isprime[31] = 1;
	int n;
	int test = 1;
	bool space = 0;
	while(cin >> n)
	{	
		if(space)
			cout << "\n";
		queue<pair<int,pair<int,string> > >q;
		q.push(make_pair(1,make_pair(1,"1")));
		cout << "Case " << test++ << ":\n";
		while(!q.empty())
		{
			int mask = q.front().first;
			int at = q.front().second.first;
			string ans = q.front().second.second;
			q.pop();
			if(mask == (1 << n)-1 && isprime[at+1])
			{
				cout << ans << "\n";
			}
			for(int i = 1; i < n; i++)
			{
				if(!(mask & (1 << i)))
				{
					if(isprime[at+i+1])
					{
						string aux = ans;
						aux += (" " + to_string(i+1));
						q.push(make_pair(mask|(1 << i),make_pair(i+1,aux)));
					}
				}
			}
		}
		space = 1;
	}
}
