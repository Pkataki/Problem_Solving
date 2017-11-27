#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int x = 1;
int y = 1;
bool ri = true;
void move()
{
	if(ri)
		y++;
	else
		y--;
	if(y > m)
	{
		y--;
		x++;
		ri  = false;
	}
	if(y < 1)
	{
		y++;
		x++;
		ri = true;
	}
}
int main()
{
	cin >> n >> m >> k;
	for(int i = 1; i < k ; i++)
	{
		cout << 2 <<  ' ';
		cout << x << ' ' << y << ' ';
		move();
		cout << x << ' ' << y << '\n';
		move();
	}
	int a = n*m - 2*(k-1);
	cout << a << ' ';
	for(int i = 0 ; i < a; i++)
	{
		cout << x << ' ' << y << ' ';
		move();
	}
	cout << '\n';
}
