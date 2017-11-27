#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
const double eps = 1e-9;
using namespace std;
int dcmp(double x)
{
    if (x < -eps) return -1;
    else if (x > eps) return 1;
    else return 0;
}


double add(double a, double b)
{
    if (abs(a + b) < eps * (abs(a) + abs(b))) return 0;
    return a + b;
}


struct Point
{
    double x,y;
    Point() {}
    Point(double x,double y) : x(x),y(y){}
    Point operator + (Point p) {return Point(add(x, p.x),add(y, p.y)); }
    Point operator - (Point p) {return Point(add(x, -p.x),add(y, -p.y)); }
    Point operator * (double a) {return Point(x * a, y * a); }
    Point operator / (double a) {return Point(x / a, y / a); }
    bool operator < (const Point p) const {return dcmp(x - p.x) < 0 || dcmp(x - p.x) == 0 && dcmp(y - p.y)<0; }
    bool operator == (const Point p) const {return dcmp(x - p.x) == 0 && dcmp(y - p.y) == 0; }
    double dot(Point p) {return add(x * p.x, y * p.y); }
    double det(Point p) {return add(x * p.y, -y * p.x); }
    double length() {return sqrt(x*x + y*y); }
    double Angle(Point p) {return acos(add(x * p.x, y * p.y)/ length() / p.length() );}
    Point Rotate(double rad) {return Point(add(x * cos(rad),- y * sin(rad)), add(x * sin(rad), y * cos(rad))); }
    Point Normal() {return Point(-y / length(), x / length()); }
};
const double PI = acos(-1);
Point p[4],P[4], O[4];
bool isSquare(Point p[])
{
    sort(p, p+4);
    return (p[0] - p[3]).dot(p[1] - p[2]) == 0 && dcmp((p[0] - p[3]).length() - (p[1] - p[2]).length()) == 0 
        && (p[0] - p[1]).det(p[2] - p[3]) == 0 && (p[1] - p[3]).det(p[0] - p[2]) == 0 && !(p[0] == p[1] || p[0] == p[2] 
            || p[0] == p [3] || p[1] == p[2] || p[1] == p[3] || p[2] == p[3]);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
            scanf("%lf%lf%lf%lf", &P[j].x, &P[j].y, &O[j].x, &O[j].y);
        
        int ans = -1;
        for (int a = 0; a < 4; a++)
        {
            for (int b = 0 ; b < 4; b++)
            {
                for (int c = 0; c < 4; c++)
                {    
                	for (int d = 0; d < 4; d++)
                    {
                        p[0] = O[0] + (P[0] - O[0]).Rotate(PI*a / 2);
                        p[1] = O[1] + (P[1] - O[1]).Rotate(PI*b / 2);
                        p[2] = O[2] + (P[2] - O[2]).Rotate(PI*c / 2);
                        p[3] = O[3] + (P[3] - O[3]).Rotate(PI*d / 2);

                        if (isSquare(p))
                        {
                            ans = (ans == -1 ? (a+b+c+d) : min(ans, a+b+c+d));
                       
                        }
                    }
                }
            }
    	}
        printf("%d\n", ans);
    }
    return 0;

}
