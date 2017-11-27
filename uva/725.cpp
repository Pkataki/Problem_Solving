#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	bool space = 0;
	while(cin >> n && n)
	{
		if(space)
			cout << "\n";
		bool found = 0;
		for(int i = 1234; i <= 98765; i++)
		{
			int ans = i*n;
			if((int)(log10(ans)+1) == 5)
			{
				stringstream ss;
				string s;
				ss << ans;
				ss >> s;
				set<char>se;
				for(int j = 0; s[j]; j++)
					se.insert(s[j]);
				if(se.size() == 5)
				{
					ss.clear();
					ss << i;
					s = "";
					if((int)(log10(i)+1) == 4)
						se.insert('0');
					ss >> s;
					for(int j = 0; s[j]; j++)
						se.insert(s[j]);
					if(se.size() == 10)
					{
						found = 1;
						cout << ans  << " / " << (s.size() == 4? "0": "")<< i << " = " << n << "\n";
					}
				}
			}
		}
		if(!found)
			cout << "There are no solutions for " << n << ".\n";
		space = 1;
	}
}
