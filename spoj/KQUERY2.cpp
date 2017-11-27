#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r,val,id,typ;
};
node v[500000];
bool cmp( node a, node b ) 
{
    if ( a.val == b.val ) return a.typ > b.typ ;
	    return a.val > b.val;
}
int bit[30005];
void update(int idx)
{
	while(idx <= 30000)
	{
		bit[idx]++;
		idx += idx & (-idx);
	}
}
int query(int idx)
{
	int sum = 0;
	while(idx)
	{
		sum += bit[idx];
		idx -= idx & (-idx);
	}
	return sum;
}
int ans[500005];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		v[i].val = a;
		v[i].id = i;
		v[i].typ = 0;
	}
	int q;
	cin >> q;
	for(int i = n+1; i <= n+q; i++)
	{
		int l,r,a;
		cin >> l >> r >> a;
		v[i].val = a;
		v[i].id = i;
		v[i].l = l;
		v[i].r = r;
		v[i].typ = 1;
	}
	sort(v+1,v + (n+q+1),cmp);

	for(int i = 1; i<= n+q; i++)
	{
		if(v[i].typ == 0)
		{
			update(v[i].id);
		}
		else
		{
			ans[v[i].id] = query(v[i].r) - query(v[i].l-1);
		}
	}
	for(int i = n+1; i<= n+q; i++)
		cout << ans[i] << '\n';

	return 0;
}
