#include <bits/stdc++.h>
using namespace std;
#define py first
#define px second
const int MAXN = 500005;
#define ll long long
#define x first
#define y second
typedef pair<ll,ll> point;
point points[MAXN];
double EPS = 1e-6;
bool compare(point a, point b)
{
	return a.px < b.px;
}
map<pair<ll,ll>, int>mapa;
long long poww(long long x, long long b)
{
	return x*x;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> points[i].px >> points[i].py;
		mapa[make_pair(points[i].px,points[i].py)] = i;
	}
	sort(points, points+ n, compare);
	long long best = (1LL << 61);
	multiset<point>s;
	s.insert(points[0]);
	int left = 0;
	int ans1,ans;
	auto it = s.begin();
	for(int i = 1; i < n ; i++)
	{
		while(left < i && ( points[i].px - points[left].px) > best)
			s.erase(points[left++]);
		it = s.lower_bound(make_pair(points[i].py - best, -1));
 
		for(;it != s.end() && points[i].py + best >= it->py ; it++)
		{
			long long d = poww(points[i].py - it->py, 2) + poww(points[i].px - it->px, 2);
			if(d < best)
			{
				best = d;
				ans1 = mapa[make_pair(points[i].px,points[i].py)];
				ans = mapa[make_pair(it->px,it->py)];
			}
		}
		s.insert(points[i]);
	}
	cout << points[ans].px << ' ' << points[ans].py << '\n'  << points[ans1].px << ' ' << points[ans1].py << '\n';
	//cout << points[min(ans,ans1)].px << ' ' << points[min(ans,ans1)].py << " --> " << points[max(ans,ans1)].px << ' ' << points[max(ans,ans1)].py << endl;
 	return 0;
} 