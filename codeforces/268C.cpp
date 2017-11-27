#include<bits/stdc++.h>
using namespace std;
int main()
{
	int w, h;
	while (scanf("%d%d", &w, &h) >= 1)
	{
		printf("%d\n", min(w, h) + 1);
		for (int i = 0; i <= min(w, h); i++)
			printf("%d %d\n", i, min(w,h) - i);
	}	
}
