#include <bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	scanf("%d",&test);
	for(int t = 1; t <= test; t++)
	{
		int n;
		cin >> n;
		int h[n];
		int w[n];
		for(int i = 0; i < n ; i++)
			scanf("%d",&h[i]);
		for(int i = 0; i < n ; i++)
			scanf("%d",&w[i]);

		int lis[n];
		int lds[n];
		int max_i = 0;
		int max_d = 0;
		for(int i = 0 ; i < n ; i++)
		{
			lis[i] = lds[i] = w[i];
			for(int j = 0 ; j < i ; j++)
			{
				if(h[i] > h[j])
					lis[i] = max(lis[i],w[i] + lis[j]);
				if(h[i] < h[j])
					lds[i] = max(lds[i],w[i] + lds[j]);
			}
			max_i = max(max_i, lis[i]);
			max_d = max(max_d, lds[i]);
		}
		if(max_i >= max_d)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", \
                t, max_i, max_d);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", \
                t, max_d, max_i);

	}
	return 0;
}
