#include<bits/stdc++.h>
using namespace std;
pair<int,pair<int,int> > c[1005];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d",&c[i].second.first,&c[i].first);
		c[i].second.second = i+1;
	}
	sort(c,c+n,greater<pair<int,pair<int,int> > >());
	int k;
	scanf("%d",&k);
	set<pair<int,int> >s;
	for(int i = 0; i < k; i++)
	{
		int a;
		scanf("%d",&a);
		s.insert(make_pair(a,i+1));
	}
	vector<pair<int,int> >v;
	int request = 0;
	int money = 0;
	for(int i = 0; i < n; i++)
	{
		set<pair<int,int> >::iterator it = s.lower_bound(make_pair(c[i].second.first,-1));
		if(it == s.end())
		{
			continue;
		}
		v.push_back(make_pair(c[i].second.second,it->second));
		request++;
		money += c[i].first;
		s.erase(it);
	}
	printf("%d %d\n",request,money);
	for(int i = 0; i < v.size(); i++)
	{
		printf("%d %d\n",v[i].first,v[i].second);
	}

}
