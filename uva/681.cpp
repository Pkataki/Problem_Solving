#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9
typedef struct point
{
	double x,y;
	point()
	{
	}
	point(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
	bool operator < (point p) const
	{
		if(fabs( x - p.x) > EPS)
		{
			return x < p.x;
		}
		return y < p.y;
	}
	bool operator == (point p) const
	{
		return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
	}
}point;
double cross(point o, point a, point b)
{
	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}
bool cmp(point a, point b)
{
	if(fabs(a.y - b.y) > EPS)
		return a.y < b.y;
	return a.x < b.x;
}
vector<point> Convex_hull(vector<point> p)
{
	sort(p.begin(),p.end(),cmp);
	int n = p.size();
	vector<point> hc(2*n);
	int k = 0;
	for(int i = 0; i < n; i++)
	{
		while(k >= 2 && cross(hc[k-2],hc[k-1],p[i]) <= 0) k--;
		hc[k++] = p[i];
	}
	for(int i = n-2, t = k+1; i >= 0; i--)
	{
		while(k >= t && cross(hc[k-2], hc[k-1], p[i]) <= 0)k--;
			hc[k++] = p[i];
	}
	hc.resize(k);
	return hc;
}
main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	cout << test <<"\n";
	vector<point>p;
	int n;
	while(test--)
	{
		p.clear();
		cin >> n;
		int x,y;
		for(int i = 0; i < n; i++)
		{
			cin >> x >> y;
			p.push_back(point(x,y));
		}
		if(test)
			cin >> x;
		p = Convex_hull(p);
		cout << p.size() << "\n";
		for(int i = 0; i < (int)p.size(); i++)
		{
			cout <<fixed << setprecision(0) <<  p[i].x << " " << p[i].y << "\n";		
		}
		if(test)
			cout << "-1\n";
	}
}
