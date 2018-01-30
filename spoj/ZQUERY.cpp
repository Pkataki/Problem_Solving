#include<bits/stdc++.h>
using namespace std;

#define sq 333
const int maxn = 100100;

int n, q;

int c[maxn];
int ans[maxn];


struct no {
	int l, r, bucket, id;
	no(){}
	no(int l, int r, int id):l(l), r(r), id(id) {
		bucket = r/sq;
	}
	bool operator < (no other) const {
		if(bucket != other.bucket)
			return bucket < other.bucket;
		else
			return l < other.l;
	}
} query[maxn];

int pref[100100];

multiset<int>ms;
deque<int>dq[maxn];

void add(int x, int op)
{

	if(dq[pref[x]].size() > 1)
	{
		int re = dq[pref[x]].back() - dq[pref[x]].front();
		ms.erase(ms.find(re));
	}
	if(op)
		dq[pref[x]].push_front(x);
	else
		dq[pref[x]].push_back(x);
	if(dq[pref[x]].size() > 1)
	{
		int cur = dq[pref[x]].back() - dq[pref[x]].front();
		ms.insert(cur);
	}
}

void rem(int x, int op)
{

	if(dq[pref[x]].size() > 1)
	{
		int re = dq[pref[x]].back() - dq[pref[x]].front();
		ms.erase(ms.find(re));
	}
	if(op && dq[pref[x]].size() > 0)
		dq[pref[x]].pop_front();

	else if(dq[pref[x]].size() > 0)
		dq[pref[x]].pop_back();

	if(dq[pref[x]].size() > 1)
	{
		int cur = dq[pref[x]].back() - dq[pref[x]].front();
		ms.insert(cur);
	}
	
}

int main() {
	scanf("%d %d", &n, &q);
	pref[0] = 50020;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
		pref[i] = pref[i-1] + c[i];
	}

	for(int i = 0; i < q; ++i)
	{
		int v, k;
		scanf("%d %d", &v, &k);
		v--;
		query[i] = no(v, k, i);
	}
	sort(query, query + q);
	dq[pref[0]].push_front(0);
	int l = 0;
	int r = 0;
	for(int i = 0; i < q; ++i)
	{
		while(query[i].l < l)
		{
			l--;
			add(l, 1);
		}
		
		while(r < query[i].r)
		{
			r++;
			add(r,0);
		}
		
		while(l < query[i].l)
		{

			rem(l,1);
			l++;
		}
		
		while(query[i].r < r)
		{
			rem(r,0);
			r--;
		}
		//cout << l << ' ' << r << endl;
		if(!ms.empty())
		ans[query[i].id] = *ms.rbegin();
	}
	for(int i = 0; i < q; ++i)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}
