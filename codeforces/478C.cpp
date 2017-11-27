#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long v[3];
	for(int i = 0; i < 3; i++)
		scanf("%lld",&v[i]);
	sort(v,v+3);
	if(2*(v[0]+v[1]) <= v[2])
		printf("%lld\n",(v[0]+v[1]));
	else
		printf("%lld\n",((v[0]+v[1]+v[2])/3));
}

