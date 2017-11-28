#include<bits/stdc++.h>
using namespace std;
class EllysBottles
{
	public :  double getVolume(vector <int> bottles, int k)
	{
		int k = min(k,2000000);
		multiset<double>s;
		for(auto i : bottles)
			s.insert(i);
		for(int i = 0; i < k; i++)
		{
			double mi = *s.begin();
			s.erase(s.begin());
			double ma = *s.rbegin();
			s.erase(s.rbegin());
			double m = (mi + ma) / 2.0;
			s.insert(m);
			s.insert(m);	
		}
		return *s.begin();
	}
};