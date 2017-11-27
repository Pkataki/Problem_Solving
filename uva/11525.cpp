#include<bits/stdc++.h>
using namespace std;
int bit[50005];
int get(int idx)
{
	int sum = 0;
	while(idx)
	{
		sum += bit[idx];
		idx -= idx & (-idx);
	}
	return sum;
}

void update(int idx, int val)
{
	while(idx < 50005)
	{
		bit[idx] += val;
		idx += idx & -idx;
	}
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
			update(i,1);
		
		for(int i = 0; i < n; i++)
		{
			int a;
			scanf("%d",&a);
			a++;
			int lo,hi;
			lo = 1;
			hi = n;
			while(lo < hi)
			{
				int mid = (lo+hi) >> 1;
				if(get(mid) >= a)
					hi = mid;
				else
					lo = mid+1;
			}
			if(i)
				printf(" ");
			printf("%d",lo);
			update(lo,-1);
		}
		puts("");
	}
}
