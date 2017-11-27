#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if(n&1)
		cout << "0\n";
	else
		cout << (n%4 == 0 ? (n/4) - 1 : n/4) << '\n';
}
