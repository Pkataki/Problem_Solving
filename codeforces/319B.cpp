#include<bits/stdc++.h>
using namespace std;
int ans[100005];
int main()
{
	int n;
	scanf("%d",&n);
	int v[n];
	for(int i = 0; i < n; i++)
		scanf("%d",&v[i]);
	stack<int>s;
	for(int i = n-1; i >= 0; i--)
	{
		while( s.size() && v[i] > v[s.top()])
		{
			ans[i] = max(ans[i]+1,ans[s.top()]);
			s.pop();
		}
		s.push(i);
	}
	printf("%d\n",*max_element(ans,ans+n));
}
