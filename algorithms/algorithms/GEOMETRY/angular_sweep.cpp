#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;

const double PI = acos(-1.0);

const double EPS = 1e-9;

//acha a maior quantidade de pontos que um circulo de tamanho r definido pode cobrir
int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}

int x[MAXN], y[MAXN];
struct event
{
	double angle; 
	int kind;
	bool operator < ( const event &e ) const
	{
	if ( angle != e.angle ) return angle < e.angle;
		return kind > e.kind;
	}
} events[4*MAXN];


double dist( int i, int j ) 
{
	return hypot( x[i] - x[j] , y[i] - y[j]  );
}

int main() 
{
	int n,r;
	while (scanf( "%d %d", &n, &r ))
	{
		 
		if ( !n && !r ) break ;
		for(int i = 0 ; i < n ; i++)
		      scanf( "%d %d", &x[i], &y[i] );
		      
		int ans = 1;
		for(int i = 0; i < n; i++) 
		{
			int idx = 0;
			for(int j = 0; j < n; j++)
			{
				if ( j != i && cmp(2.0*r, dist( i, j ) ) >= 0 ) 
				{
	                
	                double a = atan2( y[j] - y[i], x[j] - x[i] );
	                double b = acos( dist( i, j ) / (2 * r) );
	                events[idx++] = (event){a - b, 1};
					events[idx++] = (event){a + b, -1};
					events[idx++] = (event){a - b + 2 * PI, 1};
					events[idx++] = (event){a + b + 2 * PI, -1};
				}
            }	
        	sort( events, events + idx );
        		
			int inside = 1;
			for(int j = 0; j < idx; j++)
			{
				inside += events[j].kind;
				ans = max( ans, inside );
			}
		}
		
		printf( "It is possible to cover %d points.\n", ans );
	}

	return 0;
}
