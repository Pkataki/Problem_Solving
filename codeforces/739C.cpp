#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int mi = INT_MAX;
	while(m--)
	{
		int l,r;
		cin >> l >> r;
		mi = min((r-l)+1,mi);
	}
	cout << mi << '\n';
	for(int i = 0; i < n ; i++)
		cout << i%mi << ' ';
	cout << endl;
	return 0;
}
