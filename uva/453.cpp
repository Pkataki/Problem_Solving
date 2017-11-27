#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
const double EPS = 1e-9;
const double INF = 1e50;
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

double dist(pt a, pt b){ return (a - b).length(); }
double dot(pt a, pt b){ return a.x*b.x + a.y*b.y; }
double cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
double signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c))/2.0; }

int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}

double angle(pt a, pt b, pt c){
	pt va = b-a, v = c-a;
	//va.normalize(); **nao parece ser necessario
	pt vb(-va.y, va.x);
	return atan2( dot(v, vb), dot(v, va) );
}


//gira a em torno da origem por theta radianos
pt rotate(pt a, double theta){ return pt(cos(theta)*a.x - sin(theta)*a.y, sin(theta)*a.x + cos(theta)*a.y); }

//gira b em torno de a por theta radianos
pt rotate(pt a, pt b, double theta){ return a + rotate(b-a, theta); }

bool intersect(pt c1, double r1, pt c2, double r2, pt& p1, pt& p2){
	double d = dist(c1, c2);
	if(r1 < r2) { swap(c1, c2); swap(r1, r2); }
	if( cmp(d, r1+r2) > 0 || cmp(d, r1-r2) < 0) return false; //nao tem intersecao
	if( !cmp(d) && !cmp(r1, r2) ) return true; //sao iguais
	
	pt v = c2 - c1;
	p1 = c1 + v*r1/v.length();
	if( !cmp(d-r1-r2) || !cmp(d+r2-r1) ){ p2 = p1; return true; } //tengencia interna/externa
	
	double theta = angle(r2, d, r1);
	p2 = rotate(c1, p1, theta);
	p1 = rotate(c1, p1, -theta);
	 cout << "eita\n";
	return true;
}
int main()
{
	pt a,b;
	double r1,r2;
	while(cin >> a.x >> a.y >> r1 >> b.x >> b.y >> r2)
	{
		pt v[2];
		for(int i = 0 ; i < 2; i++)
		{
			v[i] = pt(INF,INF);
		}
		if(intersect(a,r1,b,r2,v[0],v[1]))
		{
			if(v[1] == v[0] && v[0].x == INF && v[0].y == INF)
			{
				cout << "THE CIRCLES ARE THE SAME\n";
			}
			else if(v[1] == v[0])
			{
			
				cout <<fixed << setprecision(3) <<  "(" << v[0].x << "," << v[0].y << ")\n"; 
				cout <<fixed << setprecision(3) <<  "(" << v[0].x << "," << v[0].y << ")("  << v[1].x << "," << v[1].y << ")\n" ;
			}
			else
			{
				sort(v,v+2);
				cout <<fixed << setprecision(3) <<  "(" << v[0].x << "," << v[0].y << ")("  << v[1].x << "," << v[1].y << ")\n" ;
			}
		}
		else
			cout << "NO INTERSECTION\n";
	}
	return 0;
}
