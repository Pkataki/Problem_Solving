#include<bits/stdc++.h>
using namespace std;
int v[1105];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&v[i]);
	sort(v,v+n);
	int ans = 0;
	int used = 0;
	while(used < n)
	{
		ans++;
		int h = 0;
		for(int i = 0; i < n; i++)
		{
			if(v[i] >= h)
			{
				used++;
				v[i] = -1;
				h++;
			}
		}
	}
	printf("%d\n",ans);
}
