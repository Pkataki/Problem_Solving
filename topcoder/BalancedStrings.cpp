#include<bits/stdc++.h>
using namespace std;
class BalancedStrings
{
	string gen(int len, char a, char b)
	{
		string s = "";
		for(int i = 0 ; i < len; i++)
		{
			if(i & 1)
				s += a;
			else
				s += b;
		}
		return s;
	}
	public: vector<string> findAny(int N)
	{
		vector<string>v(N);
		for(int i = 2; i < n; i++)
		{
			if(i == 2 || v[i-1][0] == 'z')
				v[i] += 'e';
			else
				v[i][0] += char(v[i -1][0] + 1);
		}
		int p = 0;
		for(int i = 2; i < n ; i++)
		{
			for(int j = i +1 ; j < n; j++)
			{
				if(v[i][0] == v[j][0])
					p++;
			}
		}
		v[0] = gen(min(1+p,100), 'a' , 'b');
		p -= min(1+p,len) - 1;
		v[1] = gen(p,'c','d');
		return v;
	}
};