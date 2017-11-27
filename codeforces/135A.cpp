#include<bits/stdc++.h>
using namespace std;
int v[100005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n ; i++)
	{
		cin >> v[i];
	}
	sort(v,v+n);
	if(v[n-1] == 1)
		v[n-1] = 2;
	else
		v[n-1] = 1;
	sort(v,v+n);
	for(int i = 0; i < n ; i++)
	{
		cout << v[i] << ' ';
	}
	cout << '\n';
	return 0;
}
