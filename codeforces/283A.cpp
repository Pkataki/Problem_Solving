#include<bits/stdc++.h>
using namespace std;
long long bit[200005];
int tam;
long long get(int idx)
{
	long long sum = 0;
	while(idx)
	{
		sum += bit[idx];
		idx -= idx & (-idx);
	}
	return sum;
}
void update(int idx, long long val)
{
	while(idx <= 200005)
	{
		bit[idx] += val;
		idx += idx & (-idx);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	tam = 1;
	long long val;
	long long sum = 0;
	int op = 0;
	for(int i = 0; i < n ; i++)
	{
		scanf("%d",&op);
		if(op == 1)
		{
			int a;
			scanf("%d %lld",&a,&val);
			sum += (val * a);
			update(1,val);
			update(a+1,-val);
		}
		else if(op == 2)
		{
			scanf("%lld",&val);
			tam++;
			sum += val;
			update(tam,val);
			update(tam+1,-val);
		}
		else
		{
			long long val1 = get(tam);
			sum -= val1;
			update(tam,-val1);
			update(tam+1,val1);
			tam--;
		}
		printf("%.10lf\n",(sum*1.0)/tam);
	}
	
	return 0;
}
