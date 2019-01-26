#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
struct P
{
	int data,id;
	P(int d=0,int i=0):data(d),id(i){}
	inline friend bool operator<(const P &a,const P &b){
		return a.id<b.id;
	}
};
int n,now;
std::vector<P >tree[100005];
inline void init(){
	now=0;
	for(int i=1;i<=n;++i)
		tree[i].clear(),tree[i].push_back(P());
}
inline void modify(int x,int d){
	for(;x<=n;x+=lowbit(x))
		tree[x].push_back(P(tree[x].back().data+d,now));
	++now;
}
inline int query(int x,int id)
{
	int ans=0;
	std::vector<P >::iterator a;
	for(;x;x-=lowbit(x))
	{
		a = std::upper_bound(tree[x].begin(),tree[x].end(),P(0,id))-1;
		ans += a->data;
	}
	return ans;
}
int main()
{
	n = 100005;
	int m;
	scanf("%d",&m);
	init();
	for(int i = 0 ; i < m; i++)
	{
		int op;
		scanf("%d",&op);
		if(op)
		{
			int t,idx;
			scanf("%d %d",&t,&idx);
			printf("%d\n",query(idx,t));
		}
		else
		{
			int val,idx;
			scanf("%d %d",&val,&idx);
			modify(idx,val);
		}
	}
	return 0;
}