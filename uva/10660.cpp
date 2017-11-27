#include <bits/stdc++.h>
using namespace std;
int mat[6][6];
int _abs(int x)
{
	if(x < 0)
		return -x;
	else
		return x;
}
int dist(int x, int y, int y1, int x1)
{
	return (_abs(x - x1) + _abs(y - y1));
}
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		memset(mat,0,sizeof(mat));
		for(int i = 0 ; i < n ; i++)
		{
			int l,r,val;
			cin >> l >> r >> val;
			mat[l][r] = val;
		}
		int ans[5];
		int min_dist = INT_MAX;
		for(int a = 0; a < 25; a++)
		{
			for(int b = a+1; b < 25; b++)
			{
				for(int c = b+1; c < 25; c++)
				{
					for(int d = c+1; d < 25; d++)
					{
						for(int e = d+1; e < 25; e++)
						{
							int sum  = 0;
							int v[5];
							for(int l = 0; l < 5; l++)
							{
								for(int r = 0; r < 5; r++)
								{
									v[0] = dist(l,r,a % 5 ,a/5) * mat[l][r];
									
									v[1] = dist(l,r,b % 5 ,b/5) * mat[l][r];
									
									v[2] = dist(l,r,c % 5 ,c/5) * mat[l][r];
									
									v[3] = dist(l,r,d % 5 ,d/5) * mat[l][r];
									
									v[4] = dist(l,r,e % 5 ,e/5) * mat[l][r];
									
									sum += *min_element(v,v+5);
									
								}	
							}
							if(sum < min_dist)
							{	
								min_dist = sum;
								int opa[] = {a,b,c,d,e};
								for(int i = 0 ; i < 5; i++)
									ans[i] = opa[i];
							}			
						}
					}
				}
			}
		}
		cout << ans[0];
		for(int i = 1; i < 5; i++)
			cout << ' ' << ans[i];
		cout << '\n';
	}
}
