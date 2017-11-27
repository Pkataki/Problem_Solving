#include <bits/stdc++.h>
using namespace std;
int main()
{	
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int v[n];
	for(int i = 0 ; i <  n ; i++)
		cin >> v[i];
	
	vector<int>s1;
	for(int a = 0; a < n ; a++)
	{
		for(int b = 0; b < n; b++)
		{
			for(int c = 0 ; c < n ; c++)
			{
				s1.push_back(v[a]*v[b]+v[c]);
			}
		}
	}
	vector<int>s2;
	for(int d = 0; d < n ; d++)
	{
		for(int e = 0; e < n; e++)
		{
			for(int f = 0 ; f < n ; f++)
			{
				if ( v[d] == 0 ) 
					continue;

				s2.push_back(v[d]*(v[e]+v[f]));
			}
		}
	}
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	int ans  = 0;
	for(int i = 0 ; i < s1.size(); i++)
	{
		int lo = lower_bound(s2.begin(),s2.end(),s1[i]) - s2.begin();
		int hi = upper_bound(s2.begin(),s2.end(),s1[i]) - s2.begin();
		ans += hi - lo;
	}
	cout << ans << '\n';


	return 0;
}
