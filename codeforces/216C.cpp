#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
int main()
{
	int n,m,k;
	cin >> n >> m >> k;

	for(int i =0; i < k ; i++)
		ans.push_back(1);
	int x = n;
	while(x <= n + m)
	{
		
		ans.push_back(x);
		x++;
		if(x <= n+m)
		{
			for(int i = 1; i < k; i++)
			{
				ans.push_back(x);
			}
		}
		x += n-2;
		if(k > 1)
			x++;
	}
	cout << ans.size() << '\n';
	for(int i= 0 ; i < ans.size() ;  i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
