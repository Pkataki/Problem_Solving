#include<bits/stdc++.h>
using namespace std;
#define x second
#define y first
/*
	type 2 - vertical line
	type 0 - start point
	type 1 - end point
*/
typedef pair<int,int> point;
struct event
{
	int type;
	point p1;
	point p2;
	event(){};
	event(point p1, point p2, int type) : p1(p1), p2(p2) ,type(type){};
};
bool compare(event a, event b)
{
	return a.p1.x < b.p1.x;
}
int n,e;
event events[2000000];
set<point>s;
main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	int p1x,p1y,p2x,p2y;
	for(int i = 0; i < n; i++)
	{
		cin >> p1x >> p1y >> p2x >> p2y;
		if(p1x == p2x)
		{
			events[e++] = event(make_pair(p1y,p1x),make_pair(p2y,p2x),2);
		}
		else
		{
			events[e++] = event(make_pair(p1y,p1x),make_pair(p2y,p2x),0);
			events[e++] = event(make_pair(p2y,p2x),make_pair(p1y,p1x),1);
		}
	}
	sort(events,events+e,compare);
	
	for(int i = 0; i < e; i++)
	{
		event ev = events[i];
		if(ev.type == 0)
		{
			s.insert(ev.p1);		
		}
		else if(ev.type == 1)
		{
			s.erase(ev.p2);
		}
		else
		{
			for(typeof(s.begin()) it = s.lower_bound(make_pair(ev.p1.y,-1)) ; it != s.end() && it->y <= ev.p2.y; it++)
			{
				cout << events[i].p1.x << " " << it->y << "\n";
			}
		}
	}
}
