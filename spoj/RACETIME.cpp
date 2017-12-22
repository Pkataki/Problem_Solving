#include<bits/stdc++.h>
using namespace std;
int v[100005];
vector<int> bl[400];
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	int len = ceil(sqrt(n)) ;
	for(int i = 0; i < n ; i++)
	{
		scanf("%d",&v[i]);
		bl[i/len].push_back(v[i]);
	}
	for(int i = 0; i < len ; i++)
	{
		sort(bl[i].begin(),bl[i].end());
	}
	while(q--)
	{
		char op;
		scanf(" %c",&op);
		if(op == 'C')
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			a--;
			b--;
			int k = a/len;
			int l = b/len;
			int ans = 0;
			int inita = a;
			int initb = b;
			for(int i = k; i <= l ; i++)
			{
				if(i == k)
				{
					 int pos = a % len;
//					 cout << "a: " << a << " b: " << initb << endl;
					 for(int j = pos; j < bl[i].size() && a <= b; j++)
					 {
//					 	cout << v[a] << ' ' << a << " ||";
					 	ans += (v[a++] <= c);
					 }
//					 cout << endl;
//					 cout << ans << " ** init\n";
				}
				else if(i == l)
				{
					 int pos = b % len;
					 for(int j = 0; j <= pos && b >= inita; j++)
					 {
					 	ans += (v[b--] <= c);
					 }
				}
				else
				{
					ans += upper_bound(bl[i].begin(),bl[i].end(),c) - bl[i].begin();
				}
			}
			printf("%d\n",ans);
		}
		else
		{
			int a,b;
			scanf("%d %d",&a,&b);
			a--;
			int k = a/len;
			for(int i = 0; i < bl[k].size(); i++)
			{
				if(v[a] == bl[k][i])
				{
					v[a] = bl[k][i] = b;
					sort(bl[k].begin(), bl[k].end());
					break;
				}
			}
		}
	}
	return 0;
}
