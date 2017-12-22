#include <bits/stdc++.h>
using namespace std;
//encontra x tal que a^x congruente b (mod m)

unordered_map<int,int> vals;

int discrete_logarithm (int a, int b, int m) {
    int n = (int) sqrt (m + .0) + 1;

    int an = 1;
    for (int i=0; i<n; ++i)
        an = (an * a) % m;

    vals.clear();
    for (int i=1, cur=an; i<=n; ++i) {
        if (!vals.count(cur))
            vals[cur] = i;
        cur = (cur * an) % m;
    }
    int res = INT_MAX - 100;
    for (int i=0, cur=b; i<=n; ++i) {
        if (vals.count(cur)) {
            int ans = vals[cur] * n - i;
            if (ans < m)
            {
                res = min(ans,res);
            }
        }
        cur = (cur * a) % m;
    }
    if(res == INT_MAX - 100)
    	return -1;
    else
    	return res;	
}
int main()
{
	int a,b,m;
	while(scanf("%d %d %d",&a,&m,&b) == 3)
	{
		if((a +m +b) == 0)
			break;
		int ans = discrete_logarithm(a,b,m);
		if(ans <= 0)
			fputs_unlocked("No Solution\n",stdout);
		else
			printf("%d\n",ans);
	}
	return 0;
}	