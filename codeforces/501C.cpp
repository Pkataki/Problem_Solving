#include <bits/stdc++.h>
using namespace std;
int d[1 << 17];
int s[1 << 17];
vector<pair<int,int> >ans;
int main()
{
	int n;
	cin >> n;
	queue<int>q;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> d[i] >> s[i];
		if(d[i] == 1)
			q.push(i);
	}
	while(!q.empty())
	{
		int at = q.front();
		q.pop();
		if(!d[at])
			continue;
		int fat = s[at];
		s[fat] ^= at;
		ans.push_back({at,fat});
		d[at]--;
		d[fat]--;
		if(d[fat] == 1)
			q.push(fat);
	}
	cout << ans.size() << '\n';
	for(int i  = 0 ; i < ans.size() ; i++)
	{
		cout << ans[i].first << ' ' << ans[i].second << '\n';  
	}
	return 0;
}
