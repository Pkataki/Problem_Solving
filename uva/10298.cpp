#include<bits/stdc++.h>
using namespace std;
char P[1000005];
int f[1000005];
int n;
int kmp_process()
{
	int i = 0, j = -1;
	f[0] = -1;
	while(i < n)
	{
		while(j >= 0 && P[i] != P[j])
			j = f[j];
		i++,j++;
		f[i] = j;
	}
	return j;
}
main()
{	
	char fim[2];
	fim[0] = '.';
	fim[1] = 0;
	while(scanf("%s",P) != EOF)
	{	
		if(!strcmp(P,fim)) break;
		n = (int)strlen(P);
		int ans = kmp_process();
		int tam = n - ans;
		if(n % tam)
			printf("1\n");
		else
        {
            bool fl = true;
            int j = 0;
            for(int i = tam ; i < n ; i++)
            {
                if(P[i] != P[j])
                {
                    fl = false;
                    break;
                }
                j++;
                if(j == tam)
                    j = 0;
            }
            if(fl)
            {
                printf("%d\n", n / tam);
            }
            else
            {
                printf("1\n");
            }
		}
	}
	
}
