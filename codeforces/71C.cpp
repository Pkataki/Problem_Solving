
#include <bits/stdc++.h>
using namespace std;
int arr[100005];
bool checkPolygonWithMidpoints(int N,
                                  int midpoints)
{

    for (int j = 0; j < midpoints; j++)
    {
        int val = 1;
 

        for (int k = j; k < N; k += midpoints)
        {
  
            val &= arr[k];
        }
 
   
        if (val && N/midpoints > 2)
        {
            cout << "YES\n";
            return true;
        }
    }
    return false;
}
 

void isPolygonPossible(int N)
{

    int limit = sqrt(N);
    for (int i = 1; i <= limit; i++)
    {

        if (N % i == 0)
        {
            if (checkPolygonWithMidpoints(N, i) ||
                checkPolygonWithMidpoints(N, (N/i)))
                return;
        }
    }
 
    cout << "NO\n";
}
 
int main()
{
	int n;
    cin >> n;
    for(int i= 0; i < n; i++)
    {
    	cin >> arr[i];
    }
    isPolygonPossible(n);
    return 0;
}
