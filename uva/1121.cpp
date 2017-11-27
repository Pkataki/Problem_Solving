#include<bits/stdc++.h>
using namespace std;
main()
{
	ios_base::sync_with_stdio(false);
	int n,s;
	while(cin >> n >> s)
	{
		deque<int>window;
		int sum = 0;
		int l = INT_MAX;
		for(int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			window.push_back(a);
			sum += a;
			while(!window.empty() && sum - window.front() >= s)
			{
				sum -= window.front();
				window.pop_front();
			}
			if(sum >= s)
			{
				l = min((int)window.size(),l);
			}
		}
		cout << (l == INT_MAX ? 0 : l) << "\n";
	}
}
