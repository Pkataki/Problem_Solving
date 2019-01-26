#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9
const int maxn = 110;
double W[maxn][maxn];
int n, m;
int mx[maxn], my[maxn]; // match arr
double lx[maxn], ly[maxn]; // label arr
int x[maxn], y[maxn]; // used arr
int hungary(int nd, int m) {
   
    x[nd] = 1;
    for(int i = 1; i <= m; i++) {
        if(y[i] == 0 && fabs(W[nd][i]-lx[nd]-ly[i]) < eps) {
            y[i] = 1;
            if(my[i] == 0 || hungary(my[i], m)) {
                my[i] = nd;
                return 1;
            }
        }
    }
    return 0;
}
double KM(int n, int m) {
    int i, j, k;
    double d;
    memset(mx, 0, sizeof(mx));
    memset(my, 0, sizeof(my));
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    for(i = 1; i <= n; i++)
        for(j = 1, lx[i] = W[i][j]; j <= m; j++)
            lx[i] = lx[i] > W[i][j] ? lx[i] : W[i][j];
    for(i = 1; i <= n; i++) {
        while(1) {
            memset(x, 0, sizeof(x));
            memset(y, 0, sizeof(y));
            if(hungary(i, m))  break;
            d = 0xfffffff;
            for(j = 1; j <= n; j++) {
                if(x[j]) {
                    for(k = 1; k <= m; k++)
                        if(!y[k])
                        d = d < lx[j]+ly[k]-W[j][k] ?
                            d : lx[j]+ly[k]-W[j][k];
                }
            }
            if(d == 0xfffffff)  break;
            for(j = 1; j <= n; j++)
                if(x[j])    lx[j] -= d;
            for(j = 1; j <= m; j++)
                if(y[j])    ly[j] += d;
        }
    }
    double res = 0;
    for(i = 1; i <= m; i++) {
        if(my[i])
            res += W[my[i]][i];
    }
    return res;
}
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF && (n || m))
	{
		
		for(int i = 1; i <= n ; i++)
		{
			for(int j = 1; j <= m ; j++)
			{
				double a;
				scanf("%lf",&W[i][j]);
				W[i][j] = -W[i][j];
			}
		}
		printf("%lf\n",-KM(n,m)/n);
	}
	return 0;
}
