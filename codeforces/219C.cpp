#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;

int main()
{
	cin >> n >> k;
	cin >> s;
	if(k == 2)
	{
		int r1 = 0;
		int r2 = 0;
		for(int i = 0; i < n; i++)
			if(s[i] != (char)(i%2 + 'A'))
				r1++;
		
		for(int i = 0; i < n; i++)
			if(s[i] != (char)((1 - i%2) + 'A'))
				r2++;
		if(r1 < r2)
		{
			cout << r1 << '\n';
			for(int i = 0; i < n;i++)
			{
				cout << (char)('A' + i % 2);
			}

		}
		else
		{
			cout << r2 << '\n';
			for(int i = 0; i < n;i++)
			{
				cout << (char)('A' + 1 - i % 2);
			}
		}
		cout << '\n';
	}
	else
	{
		int cont = 0;
		for(int i = 0; i < n; i++)
		{
			if(i && s[i]== s[i-1])
			{
				s[i] = 'A';
				while(s[i] == s[i-1] || s[i] == s[i+1])
					++s[i];

				cont++;
			}
		}
		cout << cont << '\n';
		cout << s << '\n';
	}
}
