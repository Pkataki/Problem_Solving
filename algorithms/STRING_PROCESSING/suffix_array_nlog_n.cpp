	#include<bits/stdc++.h>
using namespace std;
int RA[100010];
char s[100010];
int tempRA[100010];
int tempSA[100010];
int SA[100010];
int c[100010];
int n;
int m;
void countSort(int k)
{
	int i ,sum, maxi = max(300,n);
	memset(c,0,sizeof(c));
	for(i = 0; i < n; i++)
		c[SA[i] + k < n ? RA[SA[i] + k] : 0]++;
	for(i = sum = 0; i < maxi; i++)
	{
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for(i = 0; i < n; i++)
		tempSA[c[ SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	for(i = 0; i < n; i++)
		SA[i] = tempSA[i];
}
void construct_sa()
{
	int i,k,r;
	for(i = 0; i < n; i++)
	{
		RA[i] = s[i];
		SA[i] = i;
	}
	for( k = 1; k < n; k <<= 1)
	{
		countSort(k);
		countSort(0);
		tempRA[SA[0]] = r = 0;
		for(i = 1; i < n; i++)
			tempRA[SA[i]] = 
				(RA[SA[i]] == RA[SA[i - 1]] 
					&& RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		for(i = 0; i < n; i++)
		RA[i] = tempRA[i];
	}
	
}
int phi[100010];
int plcp[100010];
char str[100010];
int lcp[100010];
void compute_lcp()
{
	phi[SA[0]] = -1;
	for(int i = 1; i < n; i++)
	{
		phi[SA[i]] = SA[i-1];
	}
	int l = 0;
	for(int i = 0; i < n; i++)
	{
		if(phi[i] == -1)
		{
			plcp[i] = 0;
			continue;
		}
		while(s[i+l] == s[phi[i] + l]) 
			l++;
		
		plcp[i] = l;
		
		l = max(0,l-1);
	}
	for(int i = 0; i < n; i++)
		lcp[i] = plcp[SA[i]];
}
pair<int,int> string_match()
{
	pair<int,int>ans;
	int lo,hi;
	lo = 0;
	hi = n-1;
	int mid = lo;
	while(lo < hi)
	{
		mid = (lo+hi)/2;
		int res = strncmp(s+SA[mid],str,m);
		if(res >= 0)
			hi = mid;
		else
			lo = mid+1;
	}
	if(strncmp(s+SA[lo],str,m))
		return pair<int,int>(-1,-1);
	ans.first = lo;
	hi = n-1;
	lo = 0;
	mid = lo;
	while(lo < hi)
	{
		mid = (lo+hi)/2;
		int res = strncmp(s+SA[mid],str,m);
		if(res > 0)
			hi = mid;
		else
			lo = mid+1;
	}
	if(strncmp(s+SA[hi],str,m))
		hi--;
	ans.second = hi;
	return ans;
}


main()
{
	int test;
	cin >> test;
	while(test--)
	{
		scanf("%s",s);
		strcat(s,"$");
		n = (int)strlen(s);
		construct_sa();
		compute_lcp();
		int pos = -1;
		int ma = 0;
		for(int i = 0; i < n; i++)
		{
			if(lcp[i] > ma)
			{
				ma = lcp[i];
				pos = i;
			}
		}
		if(pos > -1)
		{
			strncpy(str,s+SA[pos],lcp[pos]);
			str[lcp[pos]] ='\0';
			m = (int)strlen(str);
			pair<int,int>ans1 = string_match();
			printf("%s %d\n",str,ans1.second - ans1.first+1);
		}
		else
			printf("No repetitions found!\n");
	
	}
}
