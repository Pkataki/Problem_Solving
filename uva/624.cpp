#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v(50);
pair<int,int>ans;
void solve(int pos, int mask, int sum)
{
	if(sum > n)
		return;
	if(sum > ans.first)
	{
			ans.first = sum;
			ans.second = mask;
	}
	if(pos >= m)
		return;
	solve(pos+1,mask|(1 << pos),sum+v[pos]);
	solve(pos+1,mask,sum);
}
main()
{
	while(cin >> n >> m)	
	{
		ans.first = 0;
		ans.second = 0;
		for(int i = 0; i < m; i++)
			cin >> v[i];
		
		solve(0,0,0);
		for(int i = 0; i < m; i++)
		{
			if(ans.second & (1 << i))
				cout << v[i] << " ";
		}
		cout << "sum:" << ans.first << "\n";
	}
}
