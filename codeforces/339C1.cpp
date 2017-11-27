#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	vector<int>w;
	cin >> s;
	int m;
	cin >> m;
	for(int i = s.size() - 1; i >= 0; i--)
	{
		if(s[i] == '1')
		{
			w.push_back(i+1);
		}
	}
	int t = 1;
	int sum1 = 0;
	int sum2 = 0;
	int last = -1;
	string ans = "";
	while(m--)
	{
		bool ok = 0;
		if(t)
		{
			for(int i = 0; i < w.size(); i++)
			{
				if(w[i] != last)
				{
					if(sum1 + w[i] > sum2)
					{
						ok = 1;
						last = w[i];
						ans += ' ';
						ans += std::to_string(w[i]);
						sum1 += w[i];
						break;
					}
				}
			}
		}
		else
		{
			for(int i = 0; i < w.size(); i++)
			{
				if(w[i] != last)
				{
					if(sum2+w[i] > sum1)
					{
						ok = 1;
						last = w[i];
						ans += ' ';
						ans += std::to_string(w[i]);
						sum2+=w[i];
						break;
					}
				}
			}
		}
		cout << last << ' ';
		if(!ok)
		{
			cout << "NO\n";
			return 0;
		}
		t = 1 - t;
	}
	ans.erase(ans.begin());
	cout << "YES\n" << ans << '\n';
	return 0;
}
