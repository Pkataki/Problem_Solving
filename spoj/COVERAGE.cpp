#include <bits/stdc++.h>
using namespace std;
 
const double EPS = 1e-9;
const double INF = 1e50;

#define MAXN 40001

int pa[MAXN], rk[MAXN], tCnt[MAXN];
//pai, rank, numero de nos na subarvore(se este no e o raiz)

void init(int n){
    for(int i = 0; i < n; i++){
    	pa[i] = i;
    	rk[i] = 0;
    	tCnt[i] = 1;
    }
}

int find(int x){
    int a = x;
    while(pa[a] != a) a = pa[a];
    int b = x, c;
    while(pa[b] != a){
    	c = pa[b];
    	pa[b] = a;
    	b = c;
    }
    
    return a;
}

void uf(int x, int y){
    int ax = find(x);
    int ay = find(y);
    
    if(ax == ay) return;
    if(rk[ay] > rk[ax]) swap(ax, ay);
    if(rk[ax] == rk[ay]) rk[ax]++;
    pa[ay] = ax;
    tCnt[ax] += tCnt[ay];
}

 
struct Circle
{
    double x, y, r;
    Circle(){};
    Circle(double x, double y, double r) : x(x), y(y), r(r){};
};

struct Point
{
    double x, y;
    Point(){};
    Point(double x, double y) : x(x), y(y){};
};

bool isIntersect(const Circle &c1, const Circle &c2)
{
    return ((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y) <= (c1.r + c2.r + EPS) * (c1.r + c2.r + EPS));
}

pair <Point, Point> findIntersection(Circle c1, Circle c2)
{
    c2.x -= c1.x;
    c2.y -= c1.y;
    double A = -2 * c2.x;
    double B = -2 * c2.y;
    double C = c2.x * c2.x + c2.y * c2.y + c1.r * c1.r - c2.r * c2.r;
    double x = -A * C / (A * A + B * B);
    double y = -B * C / (A * A + B * B);
    double mult = sqrt(c1.r * c1.r - C * C / (A * A + B * B)) / (sqrt(A * A + B * B));
    Point res1, res2;
    res1.x = x + B * mult;
    res1.y = y - A * mult;
    res2.x = x - B * mult;
    res2.y = y + A * mult;
    res1.x += c1.x;
    res1.y += c1.y;
    res2.x += c1.x;
    res2.y += c1.y;
    return make_pair(res1, res2);
}    


 
Point v[5005];

bool used[5005];
int comp[5005];
int vis[5005];
int n;
int vi;
int sz[5005];
int compNumber;
bool inter(Point a, Point b, double r)
{
	return isIntersect(Circle(a.x, a.y, r), Circle(b.x, b.y, r));
}

void dfs(int u)
{
    used[u] = true;
    comp[u] = compNumber;
    sz[compNumber]++;
    for (int i = 0; i < n; i++)
    {
        if (!used[i] && inter(v[u],v[i],1)) 
        {
            dfs(i);
        }
    }
}

int solve(Point c1)
{
	vi++;
	int ans = 1;
	for(int i = 0 ; i < n ; i++)
	{
		if(vis[comp[i]] != vi && inter(c1,v[i],1))
		{
			vis[comp[i]] = vi;
			ans += sz[comp[i]];
		}
	}
	return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%lf %lf",&v[i].x, &v[i].y);
    }
    if(n == 1)
    {
    	puts("2");
    	return 0;
    }
    init(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
           if(inter(v[j],v[i],1))
           {
           		uf(i,j);
           }
        }
    }
    int ans = 0;
    set<int>s;
    for(int i = 0; i < n ; i++)
	{
		comp[i] = find(i);
		sz[comp[i]]++;
		s.insert(comp[i]);
    }
    compNumber = s.size();
	for(int i = 0; i < compNumber ; i++)
	{
		ans = max(ans,sz[i]+1);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
           
            if(comp[i] != comp[j] && inter(v[i],v[j],2))
            {
            	pair <Point, Point> tmp = findIntersection(Circle(v[i].x, v[i].y, 2), Circle(v[j].x, v[j].y, 2));
        		ans = max(ans,solve(tmp.first));
				ans = max(ans,solve(tmp.second));
			}
        }
    }
    printf("%d\n",ans);
    return 0;
}  
