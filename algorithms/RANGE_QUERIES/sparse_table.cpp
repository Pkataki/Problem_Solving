#include<bits/stdc++.h>
using namespace std;
int loga[300005];
int v[300005]; 
int tree2[300005][21]; 
int n;
void rmq()
{
  for(int i = 1; i <= n; i++)
        loga[i] = 31 - __builtin_clz(i);

    for(int i = 0; i < n; i++)
    {		
    	tree2[i][0] = v[i];
    }
    for(int i = 1; (1 << i) <= n; i++)
    {
        for(int j = 0 ; j + (1<<i) <= n; j++)
        {      
        	tree2[j][i] = min(tree2[j][i-1], tree2[ j + (1 << (i-1)) ][i-1]);   
        }
    }
}

int query_min(int a,int b)
{
	if(a > b)
		swap(a,b);
    int k = b - a + 1;
    return min(tree2[a][loga[k]], tree2[b - (1 << loga[k]) + 1][loga[k]] );
}
