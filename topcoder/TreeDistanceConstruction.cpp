#include <bits/stdc++.h>
using namespace std;
int cont[100];
vector<int>graph[100];
class TreeDistanceConstruction
{
	public : vector<int> construct(vector<int> d)
	{
		vector<pair<int,int> >v(d.size());
		int mi = *min_element(d.begin(),d.end());
		
		for(int i = 0; i < d.size(); i++)
		{
			v[i].first = d[i];
			v[i].second = i;

		}
		sort(v.begin(),v.end());
		d.clear();
		vector<int>f;
		for(int i = 0 ; i < v.size(); i++)
		{
			d.push_back(v[i].first);
			f.push_back(v[i].second);
				
		}
		if(d.size() == 1)
		{
			vector<int>ans;
			ans.push_back(f[0]);
			return ans;
		}
		
		
		vector<int>ans,empty;
		
		for(int i = 0 ; i < d.size() ; i++)
			cont[d[i]]++;

		if(cont[mi] > 2)
			return empty;
		
		bool ok = 1;
		for(int i = (cont[mi] == 2 ? 2 : 1); i < d.size(); i++)
		{
			if(d[i] <= mi)
				ok = 0;
		}
		if(!ok)
			return empty;


		int lastl = 0;
		int lastr = -1;


		if(cont[mi] == 2)
		{
			if(mi == 1 && d.size() > 2)
				return ans;

			ans.push_back(f[0]);
			ans.push_back(f[1]);
			lastr = 1;

		}
		else
			lastr = lastl;

		ok = 1;
		for(int i = 0; i < d.size(); i++)
		{
			if(d[i] > 2*(cont[mi] - 1))
				ok = 0;
		}
		if(!ok)
		{
			return empty;
		}
		for(int i = (cont[mi] == 2 ? 2 : 1); i < d.size(); )
		{
			if(cont[d[i]] < 2)
				return empty;

			ans.push_back(f[lastl]);
			ans.push_back(f[i]);
			ans.push_back(f[lastr]);
			ans.push_back(f[i+1]);
			int j = i+2;
			while(j < d.size() && d[i] == d[j])
			{
				ans.push_back(f[lastl]);
				ans.push_back(f[j]);
				j++;
			}
			lastl = i;
			lastr = i+1;
			i = j;
		}
		return ans;

	}
};