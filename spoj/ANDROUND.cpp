#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20005;
int v[MAXN];
int tree[4*MAXN];
void build(int pos,int low, int high){
    if (high == low){
        tree[pos] = v[low]    ;
        return;
        }
    int mid = (low+high) / 2    ;
    build( 2*pos+1,low, mid)    ;
    build( 2*pos+2,mid+1, high) ;
    tree[pos] = tree[2*pos+1] & tree[2*pos+2] ;
    return;
}
 
int query(int pos, int low, int high, int i, int j){
    if (j < low || high < i)
        return 0x7fffffff;
    if (i <= low && high <= j)
        return tree[pos]  ;
    int mid = (low+high) / 2    ;
    return (query( 2*pos+1,low, mid, i, j) & query(2*pos+2, mid+1, high, i, j))  ;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	while(test--)
	{
		memset(tree,0,sizeof(tree));
		int n,k;
		cin >> n >> k;
		
		for(int i = 0 ; i < n ; i++)
			cin >> v[i];
		
		build(0,0,n-1);
		
		k = min(k,n/2);
		for(int i = 0 ; i < n ; i++)
		{
			if(i)
				cout << ' ';
			int ans = 0x7fffffff;
			
			if(i+k <= n-1)
				ans &= query(0,0,n-1,i,i+k);
			else if(i+k > n-1)
				ans &= query(0,0,n-1,i,n-1) & query(0,0,n-1,0,(k-n+i)%n);
			if(i-k >= 0)
				ans &= query(0,0,n-1,i-k,i);
			else if(i-k < 0)
				ans &= query(0,0,n-1,0,i) & (0,0,n-1,(n-k+i),n-1);
			cout << ans;
		}
		cout << '\n';
	}
	return 0;
}
