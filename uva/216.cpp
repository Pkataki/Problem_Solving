#include<bits/stdc++.h>
using namespace std;
const double EPS =1e9;
int main()
{
	int test = 1;
	int n;
	while(cin >> n && n)
	{
		int x[n];
		int y[n];
		for(int i = 0 ; i < n ; i++)
			cin >> x[i] >> y[i];
		int v[n];
		for(int i = 0 ; i < n ; i++)
			v[i] = i;
		double ans = DBL_MAX;
		int arr[n];
		do
		{
			double aux = 0;
			for(int i = 1; i < n ; i++)
			{
				aux += sqrt( ( x[v[i]] - x[v[i-1]] ) * ( x[v[i]] - x[v[i-1]] ) + (y[v[i]] - y[v[i-1]]) * (y[v[i]] - y[v[i-1]])) + 16.0;
			}
			if(aux < ans )
			{
				ans = aux;
				for(int i = 0 ; i < n ; i++)
					arr[i] = v[i];
			}
		}while(next_permutation(v,v+n));
		cout << "**********************************************************\n";
		cout << "Network #" << test << '\n';
		test++;
		double aux;
		for(int i = 1; i < n; i++)
		{
			aux = sqrt( (x[arr[i]] - x[arr[i-1]]) * (x[arr[i]] - x[arr[i-1]]) +  (y[arr[i]] - y[arr[i-1]]) * (y[arr[i]] - y[arr[i-1]])) + 16.0;
			cout << "Cable requirement to connect (" << x[arr[i-1]] << "," << y[arr[i-1]] << ") to (" <<x[arr[i]] << "," << y[arr[i]] << ") is " << fixed << setprecision(2) << aux << " feet.\n";
		}
		cout << "Number of feet of cable required is " <<  ans << ".\n";
	}
	return 0;
}
