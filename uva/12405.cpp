#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >> test;
	int t = 1;
	while(t <= test)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = 0;
		for(int i = 0 ; i < n ; i++)
		{
			if(s[i] == '.')
			{
				ans++;
				s[i] = '#';
				if(i+1 < n)
					s[i+1] = '#';
				if(i+2 < n )
					s[i+2] = '#';
			}
		}
		cout <<"Case " << t << ": " <<  ans << "\n";
		t++;
	}
	return 0;
}
