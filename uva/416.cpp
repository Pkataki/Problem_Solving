#include <bits/stdc++.h>
using namespace std;
string g[]= 
{
"YYYYYYN",
"NYYNNNN",
"YYNYYNY",
"YYYYNNY",
"NYYNNYY",
"YNYYNYY",
"YNYYYYY",
"YYYNNNN",
"YYYYYYY",
"YYYYNYY",
};
int main()
{
	int n;
	while(cin >> n && n)
	{
		string v[n];
		for(int i = 0 ; i < n ; i++)
			cin >> v[i];
		
		bool printed = 0;
		int burned[7];
		for(int begin = 9; begin >= n-1; begin--)
		{
			int can = 0;
			memset(burned,0,sizeof(burned));
			for(int seg = 0; seg < n ;seg++)
			{
				bool ok  = 1;
				string s  = g[begin-seg];
				for(int i = 0 ; i < 7; i++)
				{
					if(burned[i] && v[seg][i] == 'Y')
						break;
					else if( s[i] == 'Y' && v[seg][i] == 'N' )
						burned[i] = 1;
					else if( s[i] == 'N' && v[seg][i] == 'Y' )
					{
						ok = 0;
						break;
					}
				}
				if(!ok)
					break;
				can++;
			}
			if(can == n)
			{
				printed = 1;
				break;
			}
		}
		if(!printed)
			cout << "MIS";
		cout << "MATCH\n";
		
	}
	return 0;
}
