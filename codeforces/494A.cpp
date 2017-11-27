#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int open = 0;
	int dif = 0;
	int has = 0;
	bool ok  = 1;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '(')
		{
			dif++;
			open++;
		}
		else if(s[i] == ')')
		{
			dif--;
			if(open > 0)
				open--;		
		}
		else if(s[i]== '#')
		{
			has++;
			dif--;
			open = 0;
		}
		if(dif< 0)
		{
			ok = 0;
			break;
		}
	}
	if(open > 0)
		ok = 0;
	if(ok)
	{
		for(int i = 0; i < has-1; i++)
		{
			printf("1\n");
		}
		printf("%d\n",dif+1);
	}
	else
		puts("-1");
	return 0;
}
