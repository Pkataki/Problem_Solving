// Program to compute sum of ranges for different range
// queries
#include <bits/stdc++.h>
using namespace std;
 
// Variable to represent block size. This is made global
// so compare() of sort can use it.
int block;
 
// Structure to represent a query range
struct Query
{
    int L, R;
};
 
// Function used to sort all queries so that all queries 
// of same block are arranged together and within a block,
// queries are sorted in increasing order of R values.
bool compare(Query x, Query y)
{
    // Different blocks, sort by block.
    if (x.L/block != y.L/block)
        return x.L/block < y.L/block;
 
    // Same block, sort by R value
    return x.R < y.R;
}
 
// Prints sum of all query ranges. m is number of queries
// n is size of array a[].
void queryResults(int a[], int n, Query q[], int m)
{
    // Find block size
    block = (int)sqrt(n);
    cout << "block size : " << block << '\n';
 
    // Sort all queries so that queries of same blocks
    // are arranged together.
    sort(q, q + m, compare);
    
    for(int i = 0; i < m; i++)
    {
    	cout << q[i].L << ' ' << q[i].R << endl;
    }
 
    // Initialize current L, current R and current sum
    int currL = 0, currR = 0;
    int currSum = 0;
 
    // Traverse through all queries
    for (int i=0; i<m; i++)
    {
        // L and R values of current range
        int L = q[i].L, R = q[i].R;
 		cout << "L: " << L << " R: " << R << endl;
        cout << "Current L: " << currL << " R: " << currR << endl;
        cout << "Current Sum: " << currSum << endl;
        
        // Remove extra elements of previous range. For
        // example if previous range is [0, 3] and current
        // range is [2, 5], then a[0] and a[1] are subtracted
        while (currL < L)
        {
            currSum -= a[currL];
            cout << "Item removed on while (currL < L) : a[" <<currL << "] = " << a[currL] << '\n';
            currL++;
            cout << "Current L: " << currL << " R: " << currR << endl;
        	cout << "Current Sum: " << currSum << endl;
        	;
        }
 		
        // Add Elements of current Range
        while (currL > L)
        {
            currSum += a[currL-1];
            cout << "Item added on  while (currL > L) : a[" <<currL-1 << "] = " << a[currL-1] << '\n';
            currL--;
            cout << "Current L: " << currL << " R: " << currR << endl;
        	cout << "Current Sum: " << currSum << endl;
        	
        }
        ;
        while (currR <= R)
        {
            currSum += a[currR];
             cout << "Item added on while (currR <= R) : a[" <<currR << "] = " << a[currR] << '\n';
            currR++;
            cout << "Current L: " << currL << " R: " << currR << endl;
        	cout << "Current Sum: " << currSum << endl;
        }
 
        // Remove elements of previous range.  For example
        // when previous range is [0, 10] and current range
        // is [3, 8], then a[9] and a[10] are subtracted
        while (currR > R+1)
        {
            currSum -= a[currR-1];
            cout << "Item removed on  while (currR > R+1) : a[" <<currR-1 << "] = " << a[currR-1] << '\n';
            currR--;
            cout << "Current L: " << currL << " R: " << currR << endl;
        	cout << "Current Sum: " << currSum << endl;
        }
        
 
        // Print sum of current range
        cout << "Sum of [" << L << ", " << R
             << "] is "  << currSum << "\n\n\n\n\n";
    }
}
 
// Driver program
int main()
{
    int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8,15};
    int n = sizeof(a)/sizeof(a[0]);
    Query q[] = {{0, 4}, {1, 3}, {2, 4},{0,9},{5,6}};
    int m = sizeof(q)/sizeof(q[0]);
    queryResults(a, n, q, m);
    return 0;
}