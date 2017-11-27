#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
set<pii>ed;
map<pii,int>dist;
int x[] = {0,0,1,-1,1,-1,1,-1};
int y[] = {1,-1,1,-1,-1,1,0,0};
int main()
{
	int x1,y1,x0,y0;
	scanf("%d %d %d %d",&x0,&y0,&x1,&y1);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a,b,r;
		scanf("%d %d %d",&r,&a,&b);
		for(int i = a; i <= b; i++)
		{
			ed.insert(pii(r,i));
		}	
	}
	dist[pii(x0,y0)] = 0;
	queue<pii>q;
	q.push(pii(x0,y0));
	bool found = 0;
	while(!q.empty())
	{
		pii at = q.front();
		q.pop();
		if(at == pii(x1,y1))
		{
			found = 1;
			printf("%d\n",dist[pii(x1,y1)]);
			break;
		}
		for(int i = 0; i < 8; i++)
		{
			int dx = at.first + x[i];			
			int dy = at.second + y[i];
			pii next = pii(dx,dy);
			if(dist.count(next))
				continue;
			if(!ed.count(next))
				continue;
			dist[next] = dist[at] + 1;
			q.push(next);
		}
	}
	if(!found)
		puts("-1");
	return 0;
}
