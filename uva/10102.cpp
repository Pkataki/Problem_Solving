#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	while(cin >> n)
	{
		int mat[n][n];
		vector<pair<int,int> > begin,end;
		string s;
		for(int i = 0; i < n; i++)
		{
			cin >> s;
			for(int j = 0; s[j] ; j++)
			{
				if(s[j] == '1')
				{
					begin.push_back(make_pair(i,j));
				}
				else if(s[j] == '3')
					end.push_back(make_pair(i,j));
			}
		}
		vector<int>result;
		for(int i = 0; i < begin.size(); i++)
		{
			int ans = INT_MAX;
			for(int j = 0; j < end.size(); j++)
			{
				ans = min(ans,abs(begin[i].first - end[j].first) + abs(begin[i].second - end[j].second));
			}
			result.push_back(ans);
		}
		cout << *max_element(result.begin(),result.end()) << '\n';
	}
}
