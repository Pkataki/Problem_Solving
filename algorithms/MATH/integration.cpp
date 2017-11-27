#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
   return pow(sin(x),10);
}

double int_trapezium(double from, double to, double n)
{
   double h = (to - from) / n;
   double sum = func(from) + func(to);
   int i;
   for(i = 1;i < n;i++)
       sum += 2.0*func(from + i * h);
   return  h * sum / 2.0;
}
 
double int_simpson(double from, double to, double n)
{
   double h = (to - from) / n;
   double sum1 = 0.0;
   double sum2 = 0.0;
   int i;
 
   double x;
 
   for(i = 0;i < n;i++)
      sum1 += func(from + h * i + h / 2.0);
 
   for(i = 1;i < n;i++)
      sum2 += func(from + h * i);
 
   return h / 6.0 * (func(from) + func(to) + 4.0 * sum1 + 2.0 * sum2);
}
int main()
{
   cout << fixed << setprecision(10) << int_trapezium(1,10, 10000) << endl;

   cout << fixed << setprecision(10) << int_simpson(1,10, 10000) << endl;
   return 0;
}