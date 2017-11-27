#include <bits/stdc++.h>
using namespace std;
struct coder{
    int x,y,id;
    
    coder(){}
    coder(int _x, int _y, int _id) :
        x(_x), y(_y), id(_id){}
    
    bool operator < (coder X)const{
        if(x != X.x) return x < X.x;
        return y < X.y;
    }
}v[300005];
long long bit[100005];
void update(int idx)
{
	while(idx <= 100005)
	{
		bit[idx]++;
		idx += idx & (-idx);
	}
}
long long query(int idx)
{
	long long sum = 0;
	while(idx)
	{
		sum += bit[idx];
		idx -= idx & (-idx);
	}
	return sum;
}
int ans[300005];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n ; i++)
	{
		cin >> v[i].x >> v[i].y;
		v[i].id = i;
	}
	sort(v+1,v+1+n);
	for(int i =1; i <= n; )
	{
		int e = i;
		while(e <= n && v[e].x == v[i].x && v[e].y == v[i].y)
			e++;
		for(int j = i; j < e; j++)
			ans[v[j].id] = query(v[j].y);

		for(int j = i; j < e; j++)
			update(v[j].y);
		i = e;
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << '\n';

	return 0;
}
