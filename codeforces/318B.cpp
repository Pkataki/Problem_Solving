#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	vector<int>v1,v2;
	int k = -1;
	while(true)
	{
		k = s.find("heavy",k+1);
		if(k == string ::npos)
			break;
		v1.push_back(k);
	}
	k = -1;
	while(true)
	{
		k = s.find("metal",k+1);
		if(k == string ::npos)
			break;
		v2.push_back(k);
	}
	
	int r = 0;
	long long ans = 0;
	for(int l = 0; l < v1.size() ; l++)
	{
		while(r < v2.size() && v2[r] < v1[l])
		{
			r++;
		}
		ans += (long long)v2.size() - (long long)r;
	}
	cout << ans << '\n';

	return 0;
}
