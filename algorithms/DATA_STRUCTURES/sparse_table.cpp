#include<bits/stdc++.h>
using namespace std;
int loga[300000];
int c[100005]; 
int tree[100005][20]; 
int n;
void rmq2()
{
	loga[1]=0;
    for(int i = 1; i <= 16; i++)
        for(int j = (1 << i) ; j < (1<<(i+1)); j++)
            loga[j] = i;
    for(int i = 0; i < n; i++)
    	tree[i][0] = c[i];
    for(int i = 1; i <= 16; i++)
        for(int j = 0 ; j + (1<<i) - 1 <= n; j++)
            tree[j][i] = min(tree[j][i-1], tree[ j + (1 << (i-1)) ][i-1]);    
}
 
int query(int a,int b)
{
    int k = b - a + 1;
//	cout << "a: " << a << " k: " << k << " b: " << b << " log[k]:" << loga[k] << " b + 1 - (1 << loga[k]): " <<  b + 1-(1 << loga[k]) << endl;
    return min(tree[a][loga[k]], tree[b + 1 - (1 << loga[k])][loga[k]] );
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	int qu;
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	cin >> qu;
	rmq2();
	for(int i = 0; i < qu; i++)
	{
		int a,b;
		cin >> a >> b;
		cout << query(a,b) << "\n";
	}
}
     

