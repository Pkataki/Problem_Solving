#include<bits/stdc++.h>
using namespace std;
set<pair<int,string> >v;
int main()
{
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		string s;
		int a;
		int c[2] = {0};
		cin >> s >> a;
		int aux = a;
		int cont = 0;
		while(aux)
		{
			int val = aux%10;
			if(val == 7 || val == 4)
			{
				c[val&1]++;
			}
			cont++;
			aux /= 10;
		}
		if(c[0] == c[1] && (c[0] + c[1]) == cont)
		{
			v.insert(make_pair(a,s));
		}
	}
	if(v.size() > 0)
	{
		auto it = v.begin();
		cout << it->second << '\n';
	}
	else
	{
		cout << "-1\n";
	}

	return 0;

}
