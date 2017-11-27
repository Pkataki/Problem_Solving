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

int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}
bool in_box(pt a, pt b, pt c){
	return ( cmp(c.x, min(a.x, b.x)) >= 0 && cmp(c.x, max(a.x, b.x)) <= 0
		&&   cmp(c.y, min(a.y, b.y)) >= 0 && cmp(c.y, max(a.y, b.y)) <= 0 );
}
double dist(pt a, pt b){ return (a - b).length(); }
double dot(pt a, pt b){ return a.x*b.x + a.y*b.y; }
double cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
double signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c))/2.0; }
bool intersect(pt a, pt b, pt c, pt d, pt& inter){
	double det = cross(b-a, d-c);
	if(fabs(det) < EPS){
		if( fabs(signed_area(a, b, c) ) < EPS){
			inter = pt(INF, INF); 
			return true; //retas coincidentes
		}
		return false; //retas paralelas
	}
	//retas concorrentes
	double ua = ( cross(d-c, a-c) )/det; //parametros (pode ser importante)
//  double ub = ( cross(b-a, a-c) )/det;
	inter = a + (b-a)*ua;
	return true;
}
bool intersect_seg(pt a, pt b, pt c, pt d, pt& inter){
	if( !intersect(a, b, c, d, inter) ) return false; //segmentos paralelos
	
	if( inter == pt(INF, INF) )
		return in_box(a, b, min(c, d)) || in_box(c, d, min(a, b)); //segmentos sobrepostos
		
	return in_box(a, b, inter) && in_box(c, d, inter); //segmentos concorrentes
}
struct segment
{
	pt a,b;
};
int main()
{
	int test;
	cin >> test;
	int n;
	while(test--)
	{
		cin >> n;
		segment v[n];
		for(int i = 0 ; i < n ; i++)
		{
			cin >> v[i].a.x >> v[i].a.y >> v[i].b.x >> v[i].b.y;
		}
		int ans = 0;
		for(int i = 0 ; i < n ; i++)
		{
			bool ok = 1;
			for(int j = 0; j < n ;j++)
			{
				if(i == j)
					continue;
				pt p;
				if(intersect_seg(v[i].a,v[i].b,v[j].a,v[j].b,p))
				{
					ok = 0;
				}
			}
			if(ok)
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
