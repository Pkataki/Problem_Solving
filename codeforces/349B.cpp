#include<bits/stdc++.h>
using namespace std;
int v[10];
int main()
{	
	int p;
	scanf("%d",&p);
	int mi = INT_MAX;
	for(int i = 1; i <= 9; i++)
	{
		scanf("%d",&v[i]);
		mi = min(mi,v[i]);
	}
	int num = p/mi;
	if(p < mi)
		printf("-1");
	while(num--)
	{
		for(int i = 9; i >= 1; i--)
		{
			if(p >= v[i] && (p-v[i])/mi >= num)
			{
				p -= v[i];
				printf("%d",i);
				break;
			}
		}
	}
	puts("");
	return 0;
}
