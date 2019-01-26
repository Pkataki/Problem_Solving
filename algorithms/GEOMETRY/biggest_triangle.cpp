#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct pt;
typedef vector<pt> polygon;

int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}

//estrutura que representa um ponto
// ou um vetor dependendo da necessidade
struct pt{
	double x, y;
	pt(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	
	double length() { return sqrt(x*x + y*y); }
	double length2() { return x*x + y*y; }
	
	pt normalize(){ return (*this)/length(); }
	
	pt operator - (pt p){ return pt(x - p.x, y - p.y); }
	pt operator + (pt p){ return pt(x + p.x, y + p.y); }
	pt operator * (double k){ return pt(x * k, y * k); }
	pt operator / (double k){ return pt(x / k, y / k); }
	bool operator < (const pt& p) const{
		if(fabs( x - p.x ) >= EPS) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p){
		return ( fabs(x - p.x) < EPS && fabs(y - p.y) < EPS );
	}
};

////////////////////
// Funcoes basicas

double dist(pt a, pt b){ return (a - b).length(); }
double dot(pt a, pt b){ return a.x*b.x + a.y*b.y; }
double cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
double signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c))/2.0; }

/////////////////////
// Orientacao

//Determina o lado que c esta em relacao ao vetor a->b
//-1  -> right
//0  -> on
//1 -> left
int side_sign(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)); }
bool cw(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)) > 0; }
bool ccw(pt a, pt b, pt c){	return cmp(signed_area(a, b, c)) < 0; }
bool colinear(pt a, pt b, pt c){ return !cmp(signed_area(a, b, c)); }

void convex_hull_2(polygon P, polygon& hull) {
	hull.clear();
	
	// Sort points lexicographically
	sort(P.begin(), P.end());
	P.resize(unique(P.begin(), P.end()) - P.begin());
	
	// Build lower hull
	for (int i = 0; i < P.size(); i ++) {
		while (hull.size() >= 2 && side_sign(hull[hull.size() - 2], hull[hull.size() - 1], P[i]) <= 0)
			hull.pop_back();
		hull.push_back(P[i]);
	}
 
	// Build upper hull
	for (int i = P.size()-2, t = hull.size() +1 ; i >= 0; i --) {
		while (hull.size() >= t && side_sign(hull[hull.size()-2], hull[hull.size()-1], P[i]) <= 0)
			hull.pop_back();
		hull.push_back(P[i]);
	}
}


double area(pt p1, pt p2, pt p3)
{
	double s = (dist(p1,p2) + dist(p2,p3) + dist(p3,p1))/2.0;
	return sqrt(s*( s - dist(p1,p2) ) * ( s - dist(p2,p3)) * (s - dist(p3,p1)) );
}

double biggest_triangle_area( polygon p)
{
	int n = p.size();
	int a = 0, b = 1, c = 2;
	int aa,bb,cc;
	aa = a;
	bb = b;
	cc = c;
	while(true)
	{
		while(true)
		{
			while(area(p[a],p[b],p[c]) < area(p[a],p[b],p[(c + 1)%n]))
			{
				c++;
				c %= n;
			}

			if(area(p[a],p[b],p[c]) < area(p[a],p[(b + 1) % n],p[c]))
			{
				b++;
				b %= n;
				continue;
			}
			else
				break;
		}
		if(area(p[a],p[b],p[c]) > area(p[aa],p[bb],p[cc]))
		{
			aa = a;
			bb = b;
			cc = c;
		}

		a = (a + 1) % n;
		if (a == b) 
			b = (b + 1) % n;
		if (b == c) 
			c = (c + 1) % n;
		if (a == 0) 
			break;
	}
	return area(p[aa],p[bb],p[cc]);
}

int main()
{
	int n;
	while(scanf("%d", &n) && n != -1)
	{
		polygon p1(n);
		
		for(int i = 0 ; i < n; i++)
		{
			scanf("%lf %lf",&p1[i].x,&p1[i].y);
		}

		polygon hull;
		convex_hull_2(p1, hull);
		printf("%.2lf\n",biggest_triangle_area(hull));
	}
	return 0;
}