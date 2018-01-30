#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int rep[maxn];
int nxt[maxn];
int find(int x)
{
	return rep[x] = (rep[x] == x ? x : find(rep[x]));
}
void unio(int x, int y)
{
	rep[find(x)] = rep[find(y)];
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i = 1; i <= n ; i++)
	{
		rep[i] = i;
		nxt[i] = i+1;
	}
	for(int i = 0; i < q; i++)
	{
		int op,a,b;
		scanf("%d %d %d",&op,&a,&b);
		if(op == 1)
			unio(a,b);
		else if(op == 2)
		{
			for(int i = a; i <= b; )
			{
				unio(i,b);
				int aux = i;
				i = nxt[i];
				nxt[aux] = nxt[b];
			}
		}
		else
		{
			if(find(a) == find(b))
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}
