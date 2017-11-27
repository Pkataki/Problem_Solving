#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void gen(string s, int depth)
{
	if(depth == 10)
		return;
	v.push_back(stoi(s));
	gen(s + '1', depth+1);
	gen(s + '0', depth+1);
}
int main()
{
	gen("1",0);
	//v.push_back(1000000000);
	sort(v.begin(),v.end());
	int n;
	cin >> n;
	int ans = upper_bound(v.begin(),v.end(),n) - v.begin();
	cout << ans << '\n';
	return 0;
}
