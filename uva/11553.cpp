#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int mat[n][n];
		vector<pair<int,int> >v(n);
		for(int i = 0; i < n; i++)
		{
			int big = INT_MIN;
			int local = 0;
			for(int j = 0; j < n; j++)
			{
				cin >> mat[i][j];
				if(mat[i][j] > big)
				{
					big = mat[i][j];
					local = j;
				}
			}
			v[i] = make_pair(big,i);
		}
		sort(v.begin(),v.end(),greater<pair<int,int> >());
		queue<pair<int,pii> >q;
		q.push(make_pair(0,make_pair(0,0)));
		int ans = INT_MIN;
		while(!q.empty())
		{
			int candy = q.front().first;
			int l = q.front().second.first;
			int c = q.front().second.second;
//			cout << "l: " << l1 << "   c: " << c1 << "\n";
			q.pop();
			if(__builtin_popcount(l) == n && __builtin_popcount(c) == n)
			{
//				cout << "cheguei\n";
				ans = max(candy,ans);
			}
			for(int i = 0; i < n; i++)
			{
				int line = v[i].second;
//				cout << line << " ****\n";
				if( !(l & ( 1 << line)))
				{
//					cout << "linha: "<< line << "\n";
					vector<pair<int,int> >v1(n);
					for(int j = 0 ; j < n; j++)
					{
						v1[j] = make_pair(mat[line][j],j);
					}
					sort(v1.begin(),v1.end());
//					for(int j = 0; j < n; j++)
//						cout << v1[j].first << " ";
//					cout << "\n";
					for(int j = 0; j < n; j++)
					{
						int col = v1[j].second;
						if(!(c & (1 << col)))
						{
//							cout << "escolhido: " << mat[line][col] << "**\n"; 
//							cout << "pos: " << v[j].second << " **\n";
							i = n;
							q.push(make_pair(candy+mat[line][col],make_pair((l | (1 << line)),(c | (1 << col)))));
							break;
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
}
