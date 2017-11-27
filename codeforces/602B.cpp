#include <bits/stdc++.h>
using namespace std;
int freq[100005];
int main()
{
	int n;
	cin >> n;
	int v[n];
	memset(freq,0,sizeof(freq));
	for(int i = 0 ; i < n ; i++)
	{
		cin >> v[i];
	}
	int r = 0;
	int ans = 0;
	set<int>s;
	for(int l = 0; l < n ; l++)
	{
		if(s.empty() && r < n)
		{
			
			s.insert(v[r]);
			freq[v[r]]++;
			r++;
		}
		if(r < n && !s.empty())
		{
			int ma = *s.rbegin();
			int mi = *s.begin();
			ma = max(ma,v[r]);
			mi = min(mi,v[r]);
			while(ma - mi <= 1 && r < n)
			{
				s.insert(v[r]);
				freq[v[r]]++;
				r++;
				ma = *s.rbegin();
				mi = *s.begin();
				ma = max(ma,v[r]);
				mi = min(mi,v[r]);
			}
		}
		freq[v[l]]--;
		if(freq[v[l]] == 0)
			s.erase(s.find(v[l]));
		ans = max(ans,r-l);

	}
	cout << ans << '\n';
	return 0;
}
