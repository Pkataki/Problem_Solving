#include<bits/stdc++.h>
using namespace std;
main()
{
	string s;
	int q_num,period;
	priority_queue< pair<int, pair<int,int> >,
		vector<pair<int, pair<int,int> > >,
		greater<pair<int, pair<int,int> > > > pq;
	while(cin >> s && s != "#")
	{
		cin >> q_num >> period;
		pq.push(make_pair(period,make_pair(q_num,period)));
	}
	int n;
	cin >> n;
	while(n--)
	{
		pair<int, pair<int, int> > at = pq.top();
		pq.pop();

		cout << at.second.first << '\n';
		
		at.first += at.second.second;
		pq.push(at);
	}
}
