#include<bits/stdc++.h>
using namespace std;
bool bulb[11][11];
int x2[] = {1,-1,0,0};
int y2[] = {0,0,1,-1};

bool on_limit(int i, int j)
{
	if(i >= 0 && j < 10 && j >= 0 && i < 10)
		return 1;
	return 0;
}

int ans;
void switch_bulb(int i, int j)
{
	bulb[i][j] ^= 1;
	for(int k = 0; k < 4; k++)
	{
		int x1 = i + x2[k];
		int y1 = j + y2[k];
		if(on_limit(x1,y1))
		{
			bulb[x1][y1] ^= 1;
		}
	}
}
void solve(int x, int y, int steps)
{
	if(steps >= ans)
		return;
	if(y == 10)
	{
		x++;
		y = 0;
	}
	
	if(x == 10)
	{
		for(int i = 0 ; i < 10; i++)
		{
			for(int j = 0 ; j < 10; j++)
				if(bulb[i][j])
					return;
		}
		ans = min(ans,steps);
		return;
	}
	
	if(x == 0)
	{
		solve(x,y+1,steps);
		
		switch_bulb(x,y);
		solve(x,y+1,steps+1);
		switch_bulb(x,y);
		return;
	}

	if(bulb[x-1][y])
	{
		switch_bulb(x,y);
		solve(x,y+1,steps+1);
		switch_bulb(x,y);
	}
	else
		solve(x,y+1,steps);

}
int main()
{
	string name;
	while(cin >> name)
	{
		if(name == "end")
			break;
		memset(bulb,0,sizeof(bulb));
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				char a;
				cin >> a;
				if(a == 'O')
					bulb[i][j] = 1; 
			}
		}
		ans = 101;
		solve(0,0,0);
		if(ans > 100)
			cout << name << " " << -1 << '\n';
		else
			cout << name << " " << ans << '\n';
	}
	return 0;
}
