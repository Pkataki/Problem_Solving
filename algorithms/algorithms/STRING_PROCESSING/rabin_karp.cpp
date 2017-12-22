#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const ull p = 31;
main()
{
	ios_base::sync_with_stdio(false);
	int test;
	cin >> test;
	while(test--)
	{
		string s,t;
		cin >> t;
		cin >> s;
		vector<ull>p_pow(max(s.length(),t.length()));
		p_pow[0] = 1ULL;
		for(int i = 1; i < p_pow.size(); i++)
		{
			p_pow[i] = p_pow[i-1]*p;
		}
		vector<ull> h(t.length());
		
		for(int i = 0; i < t.length(); i++)
		{
			h[i] = (t[i] - 'a' + 1) * p_pow[i];
			
			if(i)
				h[i] += h[i-1];
		}
		
		ull h_s = 0;
		
		for(int i = 0; i < s.size(); i++)
			h_s += (s[i] - 'a' + 1) * p_pow[i];
		vector<int>ans;
		for(int i = 0; i + s.size() - 1 < t.size() ; i++)
		{
			ull cur_h = h[i + s.size() - 1];
			if(i)
				cur_h -= h[i-1];
			
			if(cur_h == h_s * p_pow[i])
			{
				ans.push_back(i+1);
			}
		}
		if(!ans.size())
			cout << "Not Found\n";
		else
		{
			cout << ans.size() << "\n";
			for(int i = 0; i < ans.size(); i++)
			{
				if(i)
					cout << " ";
				cout << ans[i];
			}
			cout << "\n";
		}
		if(test)
			cout << "\n";
	}
}
