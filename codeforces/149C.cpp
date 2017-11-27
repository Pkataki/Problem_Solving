#include<bits/stdc++.h>
using namespace std;
pair<int,int> v[100005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v,v+n);
	set<int>s1,s2;
	int aux = (n+1)/2;
	for(int i = 0; i < n; i++)
	{
			if(i & 1)
			{
				s2.insert(v[i].second+1);
			}
			if(!(i & 1))
			{
				s1.insert(v[i].second+1);
			}

	}
	cout << s1.size() << '\n';
	for(auto it : s1)
	{
		cout << it << ' ';
	}
	cout << '\n';
	cout << s2.size() << '\n';
	for(auto it : s2)
	{
		cout << it << ' ';
	}
	cout << '\n';
	return 0;
}
