#include <bits/stdc++.h>

using namespace std;

int n, arr[101], r;
double b, f, e, v, dp[101];

double get_time(int lc, int nc)
{
  double sum = 0;
  for (int x = 0; x < arr[nc] - arr[lc]; x++)
  {
	if (x >= r)
    	sum += 1.0/(v-e*(x-r));
    else 
    	sum += 1.0/(v-f*(r-x));
  }
  return (lc) ? sum + b : sum;
}

int main()
{
  while (cin >> n && n)
  {
    for (int i = 1; i <= n; i++) 
    	cin >> arr[i];
    cin >> b >> r >> v >> e >> f;
	dp[0] = 0.0;
    for (int i = 1; i <= n; i++)
    {
      dp[i] = DBL_MAX;
      for (int j = 0; j < i; j++)
        dp[i] = min(dp[i], dp[j] + get_time(j, i));
    }

    cout << fixed << setprecision(4) << dp[n] << endl;
  }
  return 0;
}
