#include <bits/stdc++.h>
using namespace std;
class LongMansionDiv1
{
	public :  long long minimalTime(vector <int> t, int sX, int sY, int eX, int eY)
	{
		long long ans = LLONG_MAX;
		for(int i = 0; i < t.size(); i++)
		{
			long long aux = 1LL * v[i] * (abs(sY - eY) - 1);
			for(int j = min(sX,i); j <= max(sX,i); j++)
				aux += v[j];
			for(int j = min(eX,i); j <= max(eX,i); j++)
				aux += v[j];
			ans = min(ans,aux);
		}
		return ans;
	}
};