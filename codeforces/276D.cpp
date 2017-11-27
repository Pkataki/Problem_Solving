#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long l,r;
	cin >> l >> r;
	for(int i = 63; i >= 0; i--)
	{
		long long aux = (1LL << i);
		if((l & aux) ^ (r & aux))
		{
			cout << aux*2 - 1 << '\n';
			return 0;
		}
	}
	cout << "0\n";
	return 0;
}
