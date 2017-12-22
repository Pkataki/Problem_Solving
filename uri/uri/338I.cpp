#include<bits/stdc++.h>
using namespace std;
pair<long long,pair<int,int> >edges[1000005];
pair<int,int>e[10005];
#define MAXN 100001

int pa[MAXN], rk[MAXN], tCnt[MAXN];
//pai, rank, numero de nos na subarvore(se este no e o raiz)

void init(int n){
    for(int i = 0; i < n; i++){
    	pa[i] = i;
    	rk[i] = 0;
    	tCnt[i] = 1;
    }
}

int find(int x){
    int a = x;
    while(pa[a] != a) a = pa[a];
    int b = x, c;
    while(pa[b] != a){
    	c = pa[b];
    	pa[b] = a;
    	b = c;
    }
    
    return a;
}

void uf(int x, int y){
    int ax = find(x);
    int ay = find(y);
    
    if(ax == ay) return;
    if(rk[ay] > rk[ax]) swap(ax, ay);
    if(rk[ax] == rk[ay]) rk[ax]++;
    pa[ay] = ax;
    tCnt[ax] += tCnt[ay];
}

int main()
{
	ios::sync_with_stdio(0);
	long long n,k;
	int test;
	cin >> test;
	while(test--)
	{
		cin >> n >> k;
		for(int i = 0; i < n ;i++)
		{
			int a,b;
			cin >> a >> b;
			e[i] = make_pair(a,b);
		}
		int l = 0;
		for(int i = 0; i < n ; i++)
		{
			for(int j = 0; j < n ; j++)
			{
				if(i == j)
					continue;
				int d = abs(e[i].first - e[j].first);
				int d1 = abs(e[i].second - e[j].second);

				long long cost = k*(__gcd(d,d1) - 1);
				edges[l++] = make_pair(cost,make_pair(i,j));
			}
		}
		init(2*n);
		sort(edges, edges + l);	
		long long ans = 0;
		for(int i = 0; i < l; i++)
		{
			if(find(edges[i].second.first) != find(edges[i].second.second))
			{
				ans += edges[i].first;
				uf(edges[i].second.first,edges[i].second.second);
			}
		}
		cout << ans << '\n';

	}
	return 0;
}
