#include <bits/stdc++.h>

using namespace std;

vector< pair<long long,long long> >x,y;

vector< pair<long long,long long> > pts;
set< pair<int,int> >dist;

int main()
{
	ios::sync_with_stdio(0);
	for(int i=0;i<4;++i)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		pts.push_back(make_pair(x1,y1));
		pts.push_back(make_pair(x2,y2));
		dist.insert(make_pair(x1,y1));
		dist.insert(make_pair(x2,y2));
		if( x1 != x2 && y1 != y2 ) 
		{
			cout << "NO\n";
			return 0;
		}

		if( x1 == x2 )
		{
			y.push_back(make_pair(min(y1,y2),max(y1,y2)));
			
		}
		else
		{
			
			x.push_back(make_pair(min(x1,x2),max(x1,x2)));
		}
	}
	if(y.size()!=2 || x.size()!=2 || dist.size()!=4)
	{
		cout << "NO\n";
		return 0;
	}

	long long xmin,ymin,xmax,ymax;

	xmin = ymin = LLONG_MAX;
	xmax = ymax = LLONG_MIN;

	for(int i=0;i<2;++i)
	{
		xmin = min(xmin,x[i].first);
		xmax = max(xmax,x[i].second);
		ymin = min(ymin,y[i].first);
		ymax = max(ymax,y[i].second);
	}

	if( xmin == xmax && ymin == ymax ) 
	{

		cout << "1 NO\n";
		return 0 ;
	}

	int a1,a2,a3,a4;
	a1 = a2 = a3 = a4 = 0;
	for(int i=0;i<pts.size();++i){
		if( pts[i] == make_pair(xmin,ymin) ) a1 = 1;
		if( pts[i] == make_pair(xmin,ymax) ) a2 = 1;
		if( pts[i] == make_pair(xmax,ymin) ) a3 = 1;
		if( pts[i] == make_pair(xmax,ymax) ) a4 = 1;
	}
	if(a1+a2+a3+a4==4) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}