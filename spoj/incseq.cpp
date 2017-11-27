#include<bits/stdc++.h>
using namespace std;
long long tree[60][100005];
map<int,int>mapa;
int MOD = 5000000;
 
void update(int tam,int idx ,int val)
{
	while(idx <= 10005)
	{
		tree[tam][idx] = (tree[tam][idx]  + val)%5000000;
		idx += (idx & -idx);
	}
}
int query(int tam, int idx)
{
	int sum = 0;
	while(idx)
	{
		sum = (tree[tam][idx]  + sum)%5000000;
		idx -= (idx & -idx);
	}
	return sum;
}
 
int v[10005];
//int dp[55];
main()
{
	int cont = 1;
	int n, k;
	scanf("%d %d",&n,&k);
//	scanint(n);
//	scanint(k);
	vector < int > a, b;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&v[i]);
		a.push_back(v[i]);
	}
	sort(a.begin(), a.end());
	for(int i =0; i < n; i++){
		if( !mapa.count(a[i]) ){
			mapa[a[i]] = cont++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		update(1 , mapa[v[i]]  , 1);
/*		for(int j = 1; j <= k; j++)
		{
			dp[j] = query(j, v[i] - 1);
		}
*/		for(int j = 2; j <= k; j++)
		{
			update(j,  mapa[v[i]]  , query(j - 1, mapa[v[i]] - 1));
		}
	}
 
	printf("%lld\n",query(k, cont));
}
