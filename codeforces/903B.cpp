#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int h1,a1,c1,h2,a2;
	cin >> h1 >> a1 >> c1;
	cin >> h2 >> a2;
	vector<string>ans;
	while(h2 > 0)
	{

		if(h1 > a2)
		{
			h2 -= a1;
			ans.push_back("STRIKE");
		}
		else if(h1 < a2 && a1 >= h2)
		{
			h2 -= a1;
			ans.push_back("STRIKE");
		}
		else
		{
			h1 += c1;
			ans.push_back("HEAL");
		}
		if(h2 <= 0)
			break;
		h1 -= a2;
	}
	cout << ans.size() << '\n';
	for(auto t : ans)
	{
		cout << t << '\n';
	}
	return 0;
}
