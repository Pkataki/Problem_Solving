#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int l = -2000000000;
	int r = 2000000000;
	string s,a;
	int x;
	int ok = 1;
	for(int i = 0 ; i < n; i++)
	{
		cin >> s >> x >> a;
		if(a == "Y")
		{
			if(s == ">=")
				l = max(l,x);
			else if(s == ">")
				l = max(x+1,l);
			else if(s == "<=")
				r = min(x,r);
			else 
				r = min(r,x-1);
		}
		else
		{
			if(s == ">=")
				r = min(r,x-1);
			else if(s == ">")
				r = min(r,x);
			else if(s == "<=")
				l = max(x+1,l);
			else 
				l = max(x,l);
		}
		if(l > r)
		{
			ok = 0;
		}
	}
	if(ok)
		cout << l << '\n';
	else
		cout << "Impossible\n";
	return 0;
}
