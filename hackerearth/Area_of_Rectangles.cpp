#include<bits/stdc++.h>
#define MAX 100005
#define ll long long
using namespace std;
struct event {
	int ind;
	bool type;
	event() {};
	event(int ind, int type) : ind(ind), type(type) {};
};
struct point {
	int x, y;
};
int n, e;

point rects [MAX][2];
event events_v [2*MAX];
event events_h [2*MAX];

bool compare_x(event a, event b) 
{ 
	return rects[a.ind][a.type].x < rects[b.ind][b.type].x; 
}
bool compare_y(event a, event b) 
{ 
	return rects[a.ind][a.type].y < rects[b.ind][b.type].y; 
}

bool in_set [MAX];

ll area;

int main() 
{
	scanf("%d", &n);
	for (int i=0;i<n;++i) 
	{
		scanf("%d %d %d %d", &rects[i][0].x, &rects[i][0].y,&rects[i][1].x, &rects[i][1].y);
		events_v[e] = event(i, 0);
		events_h[e++] = event(i, 0);
		events_v[e] = event(i, 1);
		events_h[e++] = event(i, 1);
	}
	sort(events_v, events_v+e, compare_x);
	sort(events_h, events_h+e, compare_y);
	in_set[events_v[0].ind] = 1;
	for (int i=1;i<e;++i) 
	{
        	event c = events_v[i];
        	int cnt = 0;
        	int delta_x = rects[c.ind][c.type].x - rects[events_v[i-1].ind][events_v[i-1].type].x;
        	int begin_y;
        	if (delta_x==0)
			{
				in_set[c.ind] = (c.type==0);
				continue;
			}
        	for (int j=0;j<e;++j) 
                	if (in_set[events_h[j].ind]==1) 
					{
                        	if (events_h[j].type==0) 
							{
                                	if (cnt==0) begin_y = rects[events_h[j].ind][0].y;
                            	    	++cnt;
                        	}
							else
							{
                                	--cnt;
                                	if (cnt==0) 
									{
                                        	int delta_y = (rects[events_h[j].ind][1].y-begin_y);
                                        	area+=(ll)delta_x * (ll)delta_y;
                                	}
                			}
                	}
                	in_set[c.ind] = (c.type==0);
		}
        printf("%lld\n", area);
	return 0;
}


