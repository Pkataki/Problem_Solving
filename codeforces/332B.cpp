#include<bits/stdc++.h>
using namespace std;
pair<long long,int> t[1<<19];
long long sum[200005];
long long sumk[200005];
void build(int v,int tl,int tr)
{
    if(tl==tr)t[v]=make_pair(sumk[tr],-tr);
    else
    {
        int tm=(tl+tr)/2;
        build(v*2+1,tm+1,tr);
        build(v*2,tl,tm);
        t[v]=max(t[v*2],t[v*2+1]);
    }
}
pair<long long,int> query(int  v ,int tl,int tr,int l,int r)
{
    if(l>r)return make_pair(0,1);
    if(l==tl && r==tr)return t[v];
    int tm=(tl+tr)/2;
    return max(query(v*2,tl,tm,l,min(r,tm)),query(v*2+1,tm+1,tr,max(l,tm+1),r));
}
int main()
{
	int n,k;
	cin >> n >> k;
	sum[0] = 0;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if(i == 0)
			sum[i] = a;
		else
			sum[i] = sum[i-1] + a;
	}
	sumk[0] = sum[k-1];
	
	for(int i = 1; i+k <= n; i++)
	{
		sumk[i] = sum[i+k-1] - sum[i-1];
	}
	
	build(1,0,n-k);
	
	long long ans = -1;
	int a;
	int b;
	for(int i = 0; i + k < n; i++)
	{
		long long val = sumk[i];
		pair<long long,int> at = query(1,0,n-k,i+k,n-k);
		val += at.first;
		if(val > ans)
		{
			ans = val;
			a = i;
			b = -at.second;
		}
	}
	cout << a+1 << ' ' << b+1 << '\n';
}
