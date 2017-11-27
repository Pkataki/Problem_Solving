#include<bits/stdc++.h>
using namespace std;
main()
{
	vector<int>v(5842);
	int p2,p3,p5,p7;
	p2 = p3 = p5 = p7 = 0;
	v[0] = 1;
	for(int i = 1; i < 5842; i++)
	{
		v[i] = min(min(2*v[p2],3*v[p3]),min(5*v[p5],7*v[p7]));
		if(v[i] == 2*v[p2])
			p2++;
		if(v[i] == 3*v[p3])
			p3++;
		if(v[i] == 5*v[p5])
			p5++;
		if(v[i] == 7*v[p7])
			p7++;
	}
	int n;
	while(cin >> n && n)
	{
		cout << "The " << n;
		if(n%10==1 && (n/10)%10!=1) cout << "st";
        else if(n%10==2 && (n/10)%10!=1) cout << "nd";
        else if(n%10==3 && (n/10)%10!=1) cout << "rd";
        else cout << "th";
		cout << " humble number is " << v[n-1] << ".\n";
	}
}
