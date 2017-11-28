#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,t;
	cin >> s >> t;
	if(s.size() > t.size())
	{
		swap(s,t);
	}
	if(t.find(s) == string::npos)
	{
		cout << "0\n";
		return 0;
	}
	int g = __gcd(s.size(),t.size());
	int ans = 0;
	for(int i = 1; i <= g ; i++)
	{
		if(g % i == 0)
		{
			bool ok = 1;
			for(int j = 0; j < t.size(); j += i)
			{
				if(s.substr(0,i) != t.substr(j,i) )
				{
					ok = 0;
					break;
				}
			}
			if(ok)
				ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
