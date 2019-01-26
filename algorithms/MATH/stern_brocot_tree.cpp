#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v;
int n,m;
void build(int lx=0,int ly=1,int rx=1,int ry = 1)
{
    if(ly+ry>n||lx+rx>n) return ;

    build(lx,ly,rx+lx,ry+ly);
    v.push_back({rx+lx,ry+ly});
    build(lx+rx,ly+ry,rx,ry);
}
void clear()
{
	v.clear();
	v.push_back({0,1});
	build();
	v.push_back({1,1});
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&n,&m);
		clear();
		while(m--)
		{
			int a;
			scanf("%d",&a);
			printf("%d/%d\n",v[a-1].first,v[a-1].second);
		}
	}
	return 0;
}