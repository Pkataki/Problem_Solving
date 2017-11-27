#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int l,r;
	cin >> n;
	l = 0;
	r = n-1;
	int v[n];
	for(int i =  0 ; i < n ; i++)
	{
		cin >> v[i];
	}
	int jog[2] = {0};
	bool play = 1;
	while(l <= r)
	{
		play ^= 1;
		if(v[l] > v[r])
		{
			jog[play] += v[l];
			l++;
		}
		else
		{
			jog[play] += v[r];
			r--;
		}
	}
	cout << jog[0] << ' ' << jog[1] << '\n';
	return 0;
}
