#include<bits/stdc++.h>
using namespace std;
map<string,set<string> >mapa;
int main()
{
	int n;
	cin >> n;
	string s;
	int m;
	for(int i = 0; i < n ; i++)
	{
		cin >> s;
		cin >> m;
		for(int j = 0; j < m; j++)
		{
			string a;
			cin >> a;
			int cont = 0;
			for(auto it = mapa[s].begin(); it != mapa[s].end(); it++)
			{
				int k;
				string b = *it;
				if( (k = b.find(a)) != string::npos)
				{
					if(k + a.size() == b.size())
						cont++;
				}
				else
					cont++;
			}
			if(cont == mapa[s].size())
				mapa[s].insert(a);
		}
	}
	for(auto it = mapa.begin(); it != mapa.end(); it++)
	{
		cout << it->first << ' ';
		cout << it->second.size() << ' ';
		for(auto i = mapa[s].begin(); i != mapa[s].end(); i++)
		{
			cout << *i << ' ';
		}
		cout << endl;
	}
	return 0;
}
