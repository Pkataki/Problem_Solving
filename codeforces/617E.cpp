#include<bits/stdc++.h>
using namespace std;

#define sq 430
const int maxn = 1 << 21;

int  q;

long long v[maxn];
long long ans[maxn];

long long cnt[maxn];

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

long long pref[maxn];

int n,k;
long long ans1 = 0;
void add(long long x)
{
	ans1 += cnt[x ^ k];
	cnt[x]++;
}

void rem(long long x)
{
	cnt[x]--;
	ans1 -= cnt[x ^ k];
}

int main()
{
	scanf("%d %d %d", &n, &q, &k);
	pref[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld", &v[i]);
		pref[i] = pref[i-1] ^ v[i];
	}

	for(int i = 0; i < q; ++i)
	{
		int l,r;
		scanf("%d %d", &l, &r);
		l--;
		query[i] = no(l, r, i);
	}
	sort(query, query + q);
	int l = 0;
	int r = -1;
	//add(pref[0]);
	for(int i = 0; i < q; ++i)
	{
		while(query[i].l < l)
		{
			l--;
			add(pref[l]);
		}
		
		while(r < query[i].r)
		{
			r++;
			add(pref[r]);
		}
		
		while(l < query[i].l)
		{

			rem(pref[l]);
			l++;
		}
		
		while(query[i].r < r)
		{
			rem(pref[r]);
			r--;
		}
		ans[query[i].id] = ans1;
	}
	for(int i = 0; i < q; ++i)
	{
		printf("%I64d\n", ans[i]);
	}
	return 0;
}
