#include<bits/stdc++.h>
using namespace std;
  
const int MAX_N = 505;
const double eps = 1e-9;
const int inf = 1e9;
const int MAX_M = 20005;
class Simplex 
{
  public:
    int n, m;
    double A[MAX_M][MAX_N], B[MAX_M], C[MAX_N];
    void pivot(int l, int e)
    {
        B[l] /= A[l][e];
      
        for (int i = 1; i <= n; ++i)
            if (i != e) 
                A[l][i] /= A[l][e];

        A[l][e] = 1 / A[l][e];
      
        for (int i = 1; i <= m; ++i)
        {
            if (i != l && fabs(A[i][e]) > 0) 
            {
                B[i] -= B[l] * A[i][e];
                for(int j = 1; j <= n; ++j)
                    if (j != e) 
                        A[i][j] -= A[l][j] * A[i][e];
                 A[i][e] = -A[i][e] * A[l][e];
            }
        }
        for (int i = 1; i <= n; ++i)
            if (i != e)
                C[i] -= C[e] * A[l][i];
        C[e] = -C[e] * A[l][e];
    }
    double simplex() 
    {
        double res = 0;
        while (true)
        {
            double tmp = 0;
            int e = 0, l = 0;
            for (int i = 1; i <= n; ++i)
                if (C[i] > tmp)
                    e = i, tmp = C[i];
            
            if (!e) 
                return res;
            tmp = inf;
            for (int i = 1; i <= m; ++i)
            {
                if(A[i][e] > 0 && tmp > B[i] / A[i][e])
                {
                    tmp = B[i] / A[i][e];
                    l = i;
                }
            }
            if(tmp == inf) 
                return tmp;
            else 
                res += tmp * C[e], pivot(l, e);
        }
    }
} solve;

int x[MAX_N];
int y[MAX_N];

const double pi = acos(-1);

double sq(double a)
{
    return a*a;
}

double dist(int i, int j)
{
    return sqrt(sq(x[i] - x[j]) + sq(y[i] - y[j]));
}
  
int main()
{
    int n;
      
    scanf("%d",&n);
      
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d",&x[i], &y[i]);
    }
    int idx = 1;
    solve.n = n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            solve.A[idx][i] = 1;
            solve.A[idx][j] = 1;
            solve.B[idx] = dist(i,j);
            idx++;
        }
        solve.C[i] = 1;
    }
    solve.m = idx;
  
    printf("%.10lf\n",2*pi*solve.simplex());
    return 0;
}