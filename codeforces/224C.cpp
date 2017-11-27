#include <bits/stdc++.h>
using namespace std;
int a[100005];
int d[100005];
set <int> ans;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n; i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);// first sort all 
	if(n == 1)
	{
		cout<<-1<<endl;
		return 0;
	}
	if(n==2)
	{
		int diff = a[1]-a[0];
		ans.insert(a[0]-diff);
		ans.insert(a[1]+diff);
		if(diff%2 == 0)
		ans.insert(a[0]+diff/2)	;
	}
	else
	{
		// find all the differences 
		for(int i=0;i<n-1;i++)
		{// 5 numbers will have 4 diff
			d[i] = a[i+1] - a[i];
		}
		sort(d , d+n-1);// n numbers will give rise to n-1 diff 
		if(d[0] == d[n-2])
		{// 2 4 6 8 10 // 2 2 2 2 
			
			ans.insert(a[0]-d[0]);
			ans.insert(a[n-1]+d[0]);
		}
		else if(d[0] == d[n-3])
		{// 2 4 6 8 12 so diff is 2 2 2 2 4
			for(int i = 0;i < n-1; i++)
			{
				if(a[i+1]-a[i] == 2*d[0] && a[i+1]-a[i] != d[0])
				{
					ans.insert(a[i]+d[0]);
				}
			}
		}
	}
	cout<<ans.size()<<endl;
	for (std::set<int>::iterator it=ans.begin(); it!=ans.end(); ++it)
	std::cout <<*it<<" ";
	
	return 0;
}
