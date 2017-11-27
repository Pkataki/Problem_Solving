#include<bits/stdc++.h>
using namespace std;
struct no
{
	int pos,zero,neg;
	no(){}
	no(int pos, int zero, int neg) : pos(pos) , zero(zero), neg(neg) {}
};
no tree[400005];
int v[100000];
no combine(no a, no b)
{
	no aux;
	aux.pos = a.pos + b.pos;
	aux.neg = a.neg + b.neg;
	aux.zero = a.zero + b.zero;
	return aux;
}
void build(int node, int l, int r)
{
	if(l > r)
		return;
	if(l == r)
	{
		if(v[l] > 0)
			tree[node] = no(1,0,0);
		else if(v[l] < 0)
			tree[node] = no(0,0,1);
		else
			tree[node] = no(0,1,0);
		return ;
	}
	int mid = (l + r) >> 1;
	build(node*2, l , mid);
	build(node*2+1, mid+1, r);
	tree[node] = combine(tree[node*2], tree[node*2 + 1]);	
}
void update(int node, int l, int r, int idx, int val)
{
	if(l > r || idx < l || idx > r)
		return ;
	if(l == r)
	{
		tree[node] = no(0,0,0);
		if(val > 0)
			tree[node].pos++;
		else if(val < 0)
			tree[node].neg++;
		else
			tree[node].zero++;
		return;
	}
	int mid = (l + r) >> 1;
	if(idx >= l && idx <= mid)
		update(node*2, l, mid, idx,val);
	if(idx >= mid+1 && idx <= r)
		update(node*2+1, mid+1, r, idx,val);
	tree[node]= combine(tree[node*2],tree[node*2+1]);
}
no query(int node, int l, int r, int x, int y)
{
	if(l > r || l > y || r < x)
		return no(0,0,0);
	if(l >= x && r<= y)
	{
		return tree[node];
	}
	int mid = (l + r) >> 1;
	no p1 = query(node*2,l,mid,x,y);
	no p2 =  query(node*2+1,mid+1,r,x,y);
	return combine(p1,p2);
}
main()
{
	ios_base::sync_with_stdio(0);
	int n,q;
	while(cin >> n >> q)
	{
		for(int i = 0; i <= 4*n; i++)
			tree[i] = no(0,0,0);
		for(int i = 0; i < n; i++)
			cin >> v[i];
		build(1,0,n-1);
		while(q--)
		{
			char c;
			cin >> c;
			if(c == 'C')
			{
				int idx,val;
				cin >> idx >> val;
				update(1,0,n-1,idx-1,val);
			}
			else
			{
				int le, ri;
				cin >> le >> ri;
				no ans = query(1,0,n-1,le-1,ri-1);
				if(ans.zero > 0)
					cout << "0";
				else if(ans.neg & 1)
					cout << "-";
				else
					cout << "+";	
			}
		}
		cout << "\n";
	}
}
