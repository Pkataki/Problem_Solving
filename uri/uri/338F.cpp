#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >> test;
	getchar();
	while(test--)
	{
		string s;
		string t;
		getline(cin,s);
		getline(cin,t);
		bool k = 0;
		for(int i = 0, j = 0; i < s.size() || j < s.size() ;)
		{
			if(!k)
			{
				if(i + 1 < s.size())
				{
					cout << s[i] << s[i+1];
					i ++;
				}
				else if(i < s.size())
				{
					cout << s[i];
				}
				i++;
			}
			else
			{
				if(j + 1 < t.size())
				{
					cout << t[j] << t[j+1];
					j += 1;
				}
				else if(j < t.size())
				{
					cout << t[j];
					
				}
				j++;
			}
			k ^= 1;
		}
		cout <<'\n' ;
	}
	return 0;
}
