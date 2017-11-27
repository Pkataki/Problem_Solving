#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int v[n];
	for(int i = 0; i < n; i++)
		scanf("%d",&v[i]);
	set<int>ans;
	set<int>s;
	for(int i = 0; i < n; i++)
	{
		ans.insert(s.begin(),s.end());
		set<int>aux;
		aux.insert(v[i]);
		for(set<int>::iterator it = s.begin(); it != s.end(); it++)
		{
			aux.insert(v[i]|(*it));
		}
		s = aux;
	}
	ans.insert(s.begin(),s.end());
	printf("%lld\n",(long long)(ans.size()));

}
