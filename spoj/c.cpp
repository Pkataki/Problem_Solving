#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
struct pt{
	double x, y;
	int pos;
	
	pt(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	
	double length() { return sqrt(x*x + y*y); }
	double length2() { return x*x + y*y; }
	
	pt normalize(){ return (*this)/length(); }
	
	pt operator - (pt p){ return pt(x - p.x, y - p.y); }
	pt operator + (pt p){ return pt(x + p.x, y + p.y); }
	pt operator * (double k){ return pt(x * k, y * k); }
	pt operator / (double k){ return pt(x / k, y / k); }
	bool operator < (const pt& p) const{
		if(fabs( y - p.y ) >= EPS) return y > p.y;
		if(fabs( x - p.x ) >= EPS) return x > p.x;
		
		return pos < p.pos;
	}
	bool operator == (const pt p){
		return ( fabs(x - p.x) < EPS && fabs(y - p.y) < EPS );
	}
};
int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}
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
typedef vector<pt>polygon;

double dis(pt A, pt B)
{
	int dx = A.x - B.x;
	int dy = A.y -B.y;
	return (sqrt(dx*dx+dy*dy));
}
void convex_hull_2(polygon P, polygon& hull) {
	hull.clear();
	
	// Sort pts lexicographically
	sort(P.begin(), P.end());

	P.resize(unique(P.begin(), P.end()) - P.begin());
	// Build lower hull
	for (int i = 0; i < P.size(); i ++) {
		while (hull.size() >= 2 && side_sign(hull[hull.size() - 2], hull[hull.size() - 1], P[i]) <= 0)
			hull.pop_back();
		hull.push_back(P[i]);
	};
 
	// Build upper hull
	for (int i = P.size()-2, t = hull.size() + 1; i >= 0; i --) {
		while (hull.size() >= t && side_sign(hull[hull.size()-2], hull[hull.size()-1], P[i]) <= 0)
			hull.pop_back();
		hull.push_back(P[i]);
	};
}

double trap(pt& a, pt& b){ return 0.5*(b.x - a.x)*(b.y + a.y); }

double area(polygon& poly){
	double ret = 0.0;
	for(int i = 0; i < poly.size(); i++){
		ret += trap(poly[i], poly[(i+1)%poly.size()]);
	}
	return fabs(ret);
}

double perimeter(polygon p){
	double per = 0.0;
	for(int i = 0; i < p.size(); i++){
		per += dist(p[i], p[(i+1)%p.size()]);
	}
	return per;
}
map<pair<int,int>,bool>mapa;
int main()
{

	int n;
	scanf("%d",&n);
	vector<pt>v;
	pt p;
	for(int i = 0 ; i < n ; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(mapa.count({x,y}))
			continue;
		mapa[{x,y}] = 1;
		p.x = x;
		p.y = y;
		p.pos = i+1;
		v.push_back(p);
	}
	vector<pt>ans;
	sort(v.begin(),v.end());
	convex_hull_2(v,ans);
	printf("%d\n",(int)ans.size()-1);
	printf("%d",ans[0].pos);
	for(int i = 1; i < ans.size()-1; i++)
		printf(" %d",ans[i].pos);
	puts("");
	printf("%.20lf\n", perimeter(ans));
	printf("%.20lf\n", area(ans));
	return 0;
}