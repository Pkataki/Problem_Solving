#include<bits/stdc++.h>
using namespace std;
int HPy, ATKy, DEFy;
int HPm, ATKm, DEFm;
int HPc, ATKc, DEFc;

int main()
{
	scanf("%d %d %d", &HPy, &ATKy, &DEFy);
	scanf("%d %d %d", &HPm, &ATKm, &DEFm);
	scanf("%d %d %d", &HPc, &ATKc, &DEFc);
	
	int mn = 1e9;
	
	for (int HPx = 0; HPx <= 1000; HPx++)
	{
		for (int ATKx = 0; ATKx <= 200; ATKx++)
		{
			for (int DEFx = 0; DEFx <= 200; DEFx++)
			{
				int HPn = (HPx+HPy);
				int ATKn = (ATKx+ATKy);
				int DEFn = (DEFx+DEFy);
				
				if ((ATKn - DEFm) > 0 && ((ATKm - DEFn) <= 0 || (HPn + ATKm - DEFn - 1)/(ATKm - DEFn) > (HPm + ATKn - DEFm -1)/(ATKn - DEFm)))
					mn = min(mn, HPx*HPc + ATKx*ATKc + DEFx*DEFc);
			}
		}
	}
	printf("%d\n", mn);
	return 0;
}
