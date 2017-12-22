#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a = 0, b = 0;
	for(int i= 0; i < n ; i++)
	{
		int c;
		cin >> c;
		if(c == 1)
			a++;
		else
			b++;
	}
	if(b == 0)
		cout << a/3 << '\n';
	else if(min(a,b) == b)
	{
		cout << b + (a - b)/3 << '\n';
	}
	else
	{
		cout << a << '\n';
	}
	return 0;
}
