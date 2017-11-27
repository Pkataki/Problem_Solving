#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
	if (a.first != b.first)
	        return a.first > b.first;

	return a.second < b.second;
}
pair<int,int> v[100];
int main()
{
	int n,k;
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v,v+n,cmp);
	cout << count(v, v+n , v[k-1]) << '\n';
}
