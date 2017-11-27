#include<bits/stdc++.h>
using namespace std;
int v[100005];
int r[100005];
int l[100005];
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&v[i]);
	}
//	r[0] = 0;
	for(int i = 1; i < n; i++)
	{
		if(v[i] <= v[i-1])
			l[i] = l[i-1];
		else
			l[i] = i;
	}
	r[n-1] = n-1;
	for(int i = n-2; i >= 0; i--)
	{
		if(v[i] <= v[i+1])
			r[i] = r[i+1];
		else
			r[i] = i;
	}
	while(q--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;
		b--;
		if(l[b] <= r[a])
			puts("Yes");
		else
			puts("No");
	}
}
