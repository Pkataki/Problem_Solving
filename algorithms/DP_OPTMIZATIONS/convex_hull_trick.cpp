#include <bits/stdc++.h>
using namespace std;
#define mxn 100010
#define ll long long 
struct convex_hull_trick {
	int pointer, sz;
	vector <ll> M;
	vector <ll> B;
	vector <ll> I;

	convex_hull_trick() { pointer = sz = 0; M.clear(); B.clear(); I.clear();}
	void init() { pointer = sz = 0; M.clear(); B.clear(); I.clear();}

	bool bad(int l1,int l2,int l3) {
		return 1.0*(B[l3]-B[l1])*(M[l1]-M[l2]) > 1.0*(B[l2]-B[l1])*(M[l1]-M[l3]);
	}

	ll calc(int i, ll x) {
		return M[i]*x + B[i];
	}

	void add_line( ll m, ll b, int i) {
		if ( sz > 0 && M.back() == m ) return; ///Same Gradient. Don't add.

		M.push_back(m);
		B.push_back(b);
		I.push_back(i);
		++sz;

		while (sz >= 3 && bad(sz-3, sz-2, sz-1)) {
			M.erase(M.end()-2);
			B.erase(B.end()-2);
			I.erase(I.end()-2);
			--sz;
		}
	}

	ll query(ll x) {
		int l = 0, h = sz-1, ret = -1;
		while(l <= h) {
			int m1 = l + (h-l)/3;
			int m2 = h - (h-l)/3;
			if(calc(m1, x) > calc(m2, x)) h = m2-1, ret = m1;
			else l = m1+1, ret = m2;
		}
		return I[ret];
	}
} tree[mxn*3];

struct data {
	ll m, b; 
	int id;

} a[mxn];

pair<long long,long long>v[mxn];
bool cmp (const data &x, const data &y) {
	return x.m == y.m ? x.b > y.b : x.m > y.m;
}
bool cmp1(int x, int y, long long t)
{
	return ((v[x].first * t + v[x].second) >= (v[y].first * t + v[y].second)) ;
}


void build(int node, int l, int r) {
	tree[node].init();
	if(l == r) 
	{
		tree[node].add_line(a[l].m, a[l].b, a[l].id);
		return;
	}

	int mid = (l+r) >> 1;

	build(2*node, l, mid);
	build(2*node+1, mid+1, r);
	sort(a+l,a+r+1,cmp);
	for(int i = l; i <= r; i++) 
	{
		tree[node].add_line(a[i].m, a[i].b, a[i].id);
	}
}

int query(int node, int l, int r, int i, int j, int x) {
	if(i == l && j == r) 
	{
		return tree[node].query(x);
	}

	int mid = (l+r) >> 1;

	if(j <= mid) 
		return query(2*node, l, mid, i, j, x);
	else if(i > mid) 
		return query(2*node+1, mid+1, r, i, j, x);
	
	int p = query(2*node, l, mid, i, mid, x);
	int q = query(2*node+1, mid+1, r, mid+1, j, x);
	
	if(cmp1(p,q,x)) 
		return p;
	return q;
}

int main () 
{

	int n, q;
	long long a1,b;
	scanf("%d %d",&n,&q);
	for(int i = 1; i<= n ; i++)
	{
		scanf("%lld %lld",&b,&a1);
		v[i] = {a1, b};
		a[i] = {a1,b,i};
	}

	build(1, 1, n);

	while(q--) 
	{
		int l,r;
		long long t;
		scanf("%d %d %lld",&l,&r,&t);
		printf("%d\n", query(1, 1, n, l, r, t));
	}
	return 0;
}