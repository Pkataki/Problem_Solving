#include<bits/stdc++.h>
using namespace std;
main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		vector<int>v(n+1,0);
		for(int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v[a]++;	
		}
		int g;
		cin >> g;
		while(g--)
		{
			int a,b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for(int i = 1; i <= n; i++)
		{
			if(v[i] > 1)
			{
							
			}
		}
	}
}
