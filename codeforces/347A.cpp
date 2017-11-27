#include <bits/stdc++.h>
using namespace std;
int v[105];
int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> v[i];
	sort(v,v+n);
	swap(v[0],v[n-1]);
	for(int i = 0 ; i < n ; i++)
		cout << v[i] << ' ';
	cout << '\n';
	return 0;

}
