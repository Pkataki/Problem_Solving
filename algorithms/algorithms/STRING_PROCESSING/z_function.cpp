#include<bits/stdc++.h>
using namespace std;
vector<int> z_function(string s)
{
	vector<int>z(s.size());
	for(int i = 1 , l = 0, r = 0; i < s.size(); i++)
	{
		if(i <= r)
		{
			z[i] = min(r - i + 1, z[i - l]);
		}
		while( i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
			z[i]++;
		if(i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}
main()
{
	ios_base::sync_with_stdio(false);
	int test;
	cin >> test;
	while(test--)
	{
		string s,t;
		cin >> t >> s;
		string p = s + '#' + t;
		vector<int>z = z_function(p);
		vector<int>ans;
		for(int i = 0; i < p.size(); i++)
		{
			if(z[i] == s.size())
			{
				ans.push_back(i + 1 - s.size() - 1);
			}
		}
		if(ans.size())
		{
			cout << ans.size() << "\n";
			for(int i = 0; i < ans.size(); i++)
			{
				if(i)
					cout << " " << ans[i];
				else
					cout << ans[i];
			}
			cout << "\n";
		}
		else
			cout << "Not Found\n";
		if(test)
		{
			cout << "\n";
		}
	}
}
