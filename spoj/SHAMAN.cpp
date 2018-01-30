#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int MAXN = 5004;

const double EPS = 1e-9;

int T, N, H;
int dp[MAXN][MAXN];
int from[MAXN][MAXN];
struct pt;
typedef vector<pt> polygon;

int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}

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

int cc(pt a, pt b, pt c)
{
	return cross(b-a,c-a);
}


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
vector<pt> P;
vector<pt> hull;
int main()
{

		scanf( "%d", &N );
		for(int i = 0; i < N; i++)
		{
			int x, y;
			scanf( "%d %d", &x, &y );
			P.push_back(pt( x, y ));
		}
		
		convex_hull_2(P,hull);
		//hull.pop_back();
		H = hull.size();
		//cout << H << " ** " << endl;
		for(int i = 0 ; i < H ; i++)
		{
			from[i][i] = i;
		}
		for ( int delta = 1; delta < H; delta++ )
		{
			for(int i = 0 ; i < H; i++) {
				int j = ( i + delta ) % H;
				dp[i][j] = -1;
				int k = from[i][(j - 1 + H)%H];
				while (true) 
				{
					int val = cc( hull[i], hull[k], hull[j] );
					if ( val > dp[i][j] )
					{
						dp[i][j] = val;
						from[i][j] = k;
					}
					if ( k == from[(i + 1)%H][j] )
					      break;
					k = (k + 1) % H;
				}
			}
		}
		int ans = 0;
		for(int i  = 0 ; i < H; i++)
			for(int j = 0; j < i; j++)
		    	ans = max( ans, dp[i][j] + dp[j][i] );
		
		printf( "%d.%d\n", ans / 2, 5 * (ans%2) );

	return 0;
}