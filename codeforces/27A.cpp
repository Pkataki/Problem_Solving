#include <bits/stdc++.h>
using namespace std;
bool v[3005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v[a] = 1;
	}
	for(int i = 1; i <= 3004 ; i++)
		if(v[i] == 0)
		{
			cout << i << '\n';
			return 0;
		}
	return 0;
}
