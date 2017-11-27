#include <bits/stdc++.h>
using namespace std;
long long bit[10005];
void update(int idx, long long val, int n)
{
	while(idx <= n+1)
	{
		bit[idx] += val;
		idx += idx & (-idx);
	}
}
long long query(int idx)
{
	long long sum = 0;
	while(idx)
	{
		sum += bit[idx];
		idx -= idx & (-idx);
	}
	return sum;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		memset(bit,0,sizeof(bit));
		int n,u;
		scanf("%d %d",&n,&u);
		while(u--)
		{
			int l,r,val;
			scanf("%d %d %d",&l,&r,&val);
			l++;
			r++;
			update(l,(long long)val,n);
			update(r+1,val*-1LL,n);
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int id;
			scanf("%d",&id);
			id++;
			printf("%lld\n",query(id));
		}
	}
	return 0;
}
