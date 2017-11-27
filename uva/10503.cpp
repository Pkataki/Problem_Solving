#include <bits/stdc++.h>
using namespace std;
int l[20];
int r[20];
int spaces;
int n;
bool solve(int val, int mask, int spaces_remaning)
{
	if(spaces_remaning == 0)
	{
		if(val == l[1])
			return 1;
		return 0;
	}
	
	int ans = 0;
	
	
	for(int j = 2 ; j < n+2; j++)
	{
		if(!(mask & (1 << j)))
		{
			if(val == l[j])
				ans |= solve(r[j],mask | (1 << j), spaces_remaning-1);
			else if(val == r[j])
				ans |= solve(l[j],mask | (1 << j), spaces_remaning-1);
		}
	}
	return ans;
}
int main()
{
	while(scanf("%d",&spaces) && spaces != 0)
	{
		scanf("%d",&n);
		
		for(int i = 0 ; i < n+2 ; i++)
		{
			scanf("%d %d",&l[i],&r[i]);
		}
		int ans = solve(r[0],3,spaces);

		if(ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
