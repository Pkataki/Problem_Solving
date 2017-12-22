#include <bits/stdc++.h>
using namespace std;

int v[100005];
int bit[100005];
int n;

void update(int idx)
 {
    while(idx <= n) 
    {
        bit[idx]++;
        idx += idx & -idx;
    }
}

int query(int idx) 
{
    int ans = 0;
    while(idx > 0) {
        ans += bit[idx];
        idx -= idx & -idx;
    }
    return ans;
}

int main() 
{
    scanf("%d", &n);
    int ma = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
      /*  for(int j = 1; j <= n ; j++)
        	cout << j << ' ' << v[j] << '\n';
        cout << endl;*/
        if(x > ma)
        { 
 	   		ma = x;
 	   		v[ma]--;
        }
        else if(query(x) == i - 1)
            v[ma]++;
          
        update(x);
    }
    int ans = 1;
    for(int i = 1; i <= n; i++) {
    	
        if(v[i] > v[ans]) {
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
