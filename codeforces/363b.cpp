#include<bits/stdc++.h>
using namespace std;
int s[200000];
int main()
{
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		s[i]=s[i-1]+a;
	}

	int ap=0;
	int as = s[k];
	for (int i=k+1;i<=n;i++)
	{
		if (s[i]-s[i-k]<as){as=s[i]-s[i-k];ap=i-k;}
	}
	cout<<ap+1<<endl;
}
