#include <bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		vector<pair<int,int> > v(n);
		for(int i = 0 ; i < n ; i++)
			cin >> v[i].second ;
		for(int i = 0 ; i < n ; i++)
			cin >> v[i].first ;
		
		sort(v.begin(),v.end());
		vector<int>lis;
		vector<int>::iterator it;

		for(int i = 0;  i < n ; i++)
		{
			it = upper_bound(lis.begin(),lis.end(),v[i].second);
			if(it == lis.end())
				lis.push_back(v[i].second);
			else
				*it = v[i].second;
		}
		cout << lis.size() << '\n';
	}
}
