#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >ans;
vector<pair<int,int> >ans1;
int main()
{
	int a,b;
	cin >> a >> b;
	for(int i = 1; i <= 1000; i++)
	{
		for(int j = i+1; j <= 1000; j++)
		{
			if(i * i + j * j == a * a)
			{
				ans.push_back({i,j});
				ans.push_back({j,i});
			}
		}
	}
	for(int i = 1; i <= 1000; i++)
	{
		for(int j = i+1; j <= 1000; j++)
		{
			if(i * i + j * j == b * b)
			{
				ans1.push_back({i,-j});
				ans1.push_back({j,-i});
			}
		}
	}
	for(auto x : ans)
	{
		for(auto y : ans1)
		{
			if(x.first != y.first && x.second != y.second)
			{
				if(x.first*y.first + y.second *x.second == 0)
				{
					cout << "YES\n0 0\n";
					cout << x.first << ' ' << x.second << '\n';
					cout << y.first << ' ' << y.second << '\n';
					return 0;
				}
			}
		}
	}
	cout << "NO\n";
	return 0;
}
