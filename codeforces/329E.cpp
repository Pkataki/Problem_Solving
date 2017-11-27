#include <bits/stdc++.h>
using namespace std;
set<pair<int,int> >s;
int rd()
{
	return rand() << 15 | rand();
}
int main()
{
	for(int i = 0; i < 1000 ; i++)
	{
		srand(rd());
	}
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++)
	{
		int a,b;
		scanf("%d %d",&a, &b);
		s.insert(make_pair(a,b));
		s.insert(make_pair(b,a));
	}
	int p[n+1];
	for(int i = 0; i < n; i++)
	{
		p[i] = i+1;
	}
	for(int it = 0; it < 10000; it++)
	{
		random_shuffle(p,p+n);
		p[n] = p[0];
		int cont = 0;
		for(int i = 0; i < n; i++)
		{
			if(!s.count(make_pair(p[i],p[i+1])))
				cont++;
		}
		if(cont >= m)
		{
			for(int i = 0;  m > 0; i++)
			{
				if(!s.count(make_pair(p[i],p[i+1])))
				{
					printf("%d %d\n", p[i], p[i+1]);
					m--;
				}
			}
			return 0;
		}
		
	}
	puts("-1");
	return 0;
}
