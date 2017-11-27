#include<bits/stdc++.h>
using namespace std;
int r[200005];
int rep[200005];
void init(int n)
{
	for(int i = 1; i <= n; i++)
	{
		rep[i] = i;
		r[i] = 0;
	}
}
int find_set(int x)
{
	return (rep[x] == x ) ? (x) : (rep[x] = find_set(rep[x]));
}
bool is_same_set(int i, int j)
{
	if(find_set(i) == find_set(j))
		return true;
	else
		return false;
}
void unio(int x, int y)
{
	if(!is_same_set(x,y))
	{
		int px = find_set(x);
		int py = find_set(y);
		if(r[px] > r[py])
		{
			rep[py] = px;
		}
		else
		{
			rep[px] = py;
			if(r[px] == r[py])
				r[py]++;
		}
	}
}
main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n; 
		getchar();
		init(2*n);
		int ss = 0;
		int nss = 0;
		string s;
		while(getline(cin,s))
		{
			if(s[0] != 'q' && s[0] != 'c')
				break;
			istringstream iss(s);
			char c;
			iss >> c;
			int i,j;
			iss >> i;
			iss >> j;
			if(c == 'c')
			{
				unio(i,j);
			}
			else
			{
				if(is_same_set(i,j))
					ss++;
				else
					nss++;
			}
		}
		cout << ss << "," << nss << '\n';	
		if(test)
			cout << '\n';
	}
}
