#include<bits/stdc++.h>
using namespace std;
int lcs[1005][1005];
int conti[1005][1005];
int main()
{
	int k;
	while(cin >> k && k)
	{
		string s,t;
		cin >> s >> t;
		for(int i = 0; i < max(t.size(),s.size()); i++)
			lcs[i][0] = lcs[0][i] = 0;

		for(int i = 1; i <= s.size(); i++)
		{
			for(int j = 1; j <= t.size(); j++)
			{
				if(s[i-1] == t[j-1])
					conti[i][j] = conti[i-1][j-1]+1;
				else
					conti[i][j] = 0;
				lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
				if(conti[i][j])
				{
					for(int cs = conti[i][j]; cs >= k; cs--)
						lcs[i][j] = max(lcs[i][j], lcs[i-cs][j-cs]+cs);
				}
			}
		}
		cout << lcs[s.size()][t.size()] << '\n';
	}
}
