#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	vector<pair<int,pair<int,int> > >v1(25);
	while(cin >> n >> m && (n || m))
	{
		vector<int>v(n);
		for(int i = 0; i < n; i++)
			v[i] = i;
		for(int i = 0; i < m; i++)
		{
			cin >> v1[i].first >> v1[i].second.first >> v1[i].second.second;
		}
		int ans = 0;
		do
		{
			bool ok = 1;
			for(int i = 0; i < m; i++)
			{
				int pos1,pos2;
				for(int j = 0; j < n; j++)
				{
					if(v[j] == v1[i].first)
						pos1 = j;
					else if(v[j] == v1[i].second.first)
						pos2 = j;
				}
				if(v1[i].second.second < 0 && abs(pos1-pos2) < ( -v1[i].second.second))
				{	
					ok = 0;
				}
				else if(v1[i].second.second > 0 && abs(pos1-pos2) > ( v1[i].second.second ))
				{
					ok = 0;
				}
			}
			if(ok)
				ans++;
		}while(next_permutation(v.begin(),v.end()));
		
		cout << ans << '\n';
	
	}
}
