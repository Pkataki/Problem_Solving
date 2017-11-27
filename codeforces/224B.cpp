#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	set<int>s;
	int v[n];
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d",&v[i]);
		s.insert(v[i]);
		if(s.size() >= k)
			break;
	}
	if(s.size() < k)
	{
		printf("-1 -1\n");
		return 0;
	}
	int j;
	s.clear();
	for(j = i; j >= 0; j--)
	{
		s.insert(v[j]);
		if(s.size() >= k)
			break;
	}
	printf("%d %d\n",j+1,i+1);
	return 0;
}
