#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 100010;

const ll is_query = -(1LL<<62);

struct Line {
    ll m, b;
	int id;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
	HullDynamic() { clear(); }
	void init() { clear(); }

    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
    }
    void add_line(ll m, ll b, int id) {
        auto y = insert({ m, b, id});
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll query(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
//        return l.m * x + l.b;
		return l.id;
    }
} tree[MAXN*4];
pair<long long, long long >v[MAXN];
bool cmp(int x, int y, long long t)
{
	return ((v[x].first * t + v[x].second) >= (v[y].first * t + v[y].second)) ;
}


void build(int node, int l, int r) {
	tree[node].init();
	if(l == r) 
	{
		tree[node].add_line(v[l].first, v[l].second, l);
		return;
	}

	int mid = (l+r) >> 1;

	build(2*node, l, mid);
	build(2*node+1, mid+1, r);

	for(int i = l; i <= r; i++) 
	{
		tree[node].add_line(v[i].first, v[i].second, i);
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
	
	if(cmp(p,q,x)) 
		return p;
	return q;
}

int main () 
{

	int n, q;
	long long a,b;
	scanf("%d %d",&n,&q);
	for(int i = 1; i<= n ; i++)
	{
		scanf("%lld %lld",&b,&a);
		v[i] = {a, b};
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
