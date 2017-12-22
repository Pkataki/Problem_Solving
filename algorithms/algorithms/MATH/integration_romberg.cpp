
#include <bits/stdc++.h>
using namespace std;

double F (double x);
double G (double x);
double P (double x);
void romberg(double f(double), double a, double b, int n, double **R);

double F (double x)
{
  return (1.0/ (1.0 + x));
}

double G (double x)
{ 
   return (exp(x));
}

double P (double x)
{
   return (sqrt(x));
}
const double EPS = 1e-9;
int cmp(long double a, long double b = 0.0){
  if(fabs(a-b) < EPS) return 0;
  return a > b ? 1 : -1;
}
double romberg(double a, double b,
                   double(*func)(double)) {
    double approx[2][25];
    double *cur=approx[1], *prev=approx[0];

    prev[0] = 1/2.0 * (b-a) * (func(a) + func(b));
    for(int it = 1; it < 25; ++it, swap(cur, prev)) {
        if(it > 1 && cmp(prev[it-1], prev[it-2]) == 0)
            return prev[it-1];

        cur[0] = 1/2.0 * prev[0];
        double div = (b-a)/pow(2, it);
        for(double sample = a + div; sample < b; sample += 2 * div)
            cur[0] += div * func(a + sample);

        for(int j = 1; j <= it; ++j)
            cur[j] = cur[j-1] + 1/(pow(4, it) - 1)*(cur[j-1] + prev[j-1]);
    }

    return prev[24];
}


 void romberg(double f(double), double a, double b, int n, double **R)
{
  int i, j, k;
  double h, sum;


  h = b - a;
  R[0][0] = 0.5 * h * (f(a) + f(b));   
  printf(" R[0][0] = %f\n", R[0][0]);

  for (i = 1; i <= n; i++)
  { 
     h *= 0.5;
     sum = 0;
     for (k = 1; k <= pow(2,i)-1; k+=2)
     {
       sum += f(a + k * h);
     } 
     R[i][0] = 0.5 * R[i-1][0] + sum * h;  
     printf(" R[%d][0] = %f\n", i, R[i][0]);
     for (j = 1; j <= i; j++)
     {
       R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / (pow(4,j)-1); 
       printf(" R[%d][%d] = %.10f\n", i,j, R[i][j]);
     }
   }
}

int main()
{
  int n = 10;
  int i;
  double **R;
  double F(double), G(double), P(double);

  R = (double **)calloc((n+1), sizeof(double *));
  for (i = 0; i <= n; i++)
    R[i] =(double *) calloc((n+1), sizeof(double));
  printf("The first function is F(x) = 1/(1 + x)\n");
  romberg(F, 0.0, 2.0,3, R);
  printf("The second function is G(x) = exp(x)\n");
  romberg(G,-1.0, 1.0, 4, R);
  printf("The third function is P(x) = sqrt(x)\n");
  romberg(P,0.0, 1.0, 7, R);
  printf("%.10lf\n\n",romberg(0.0,1.0,P));
  return 0;
}