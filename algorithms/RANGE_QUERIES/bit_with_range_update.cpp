#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll B1[100005], B2[100005];

int N;

ll query(ll* ft, int b)
{
	ll sum = 0;
	for (; b; b -= b & (-b)) sum += ft[b];
	return sum;
}

ll query(int b) 
{
    return query(B1, b)*b - query(B2,b) ;
}

ll range_query(int i, int j)    
{
    return query(j) - query(i - 1);
}

void update(ll* ft, int k, ll v) 
{
	for (; k <= N; k += k & (-k)) ft[k] += v;
}


void range_update(int i, int j, ll v)	
{
	update(B1, i, v);
	update(B1, j + 1, -v);
	update(B2, i, v * (i-1));
	update(B2, j + 1, -v * j);
}

