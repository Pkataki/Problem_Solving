#include<bits/stdc++.h>
using namespace std;
pair<int,int>v[100005];
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n,k;
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n ; i++)
		{
			int a,b,c,d;
			scanf("%d %d %d %d", &a,&b,&c,&d);
			v[i] = make_pair(b*c*d,-a);
		}
		sort(v , v + n, greater<pair<int,int> >());
		vector<int>ans;
		for(int i = 0 ; i < k ; i++)	
			ans.push_back(-v[i].second);
		sort(ans.begin(),ans.end());
		printf("%d",ans[0]);
		for(int i = 1; i < k ; i++)
		{
			printf(" %d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
