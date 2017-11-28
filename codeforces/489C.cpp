#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	string s,s1;
	int n,m,x;
    cin >> n>> m;
    x = m;
    if(n==1 && m<10)
	{
		cout<<m<<" "<<m;
		return 0;
	}
    if((n>1 && m==0)||(n==1 && m>9))
	{
		cout<<"-1 -1";
		return 0;
	}
    for(int i = 0; i < n; i++)
    {
        if(x > 8)
		{	
			s=s+"9";
			x-=9;
		}
        else if(x < 9)
		{
			s+=char(x+48);
			x=0;
		}
    }
    if(x != 0)
	{	
		cout<<"-1 -1";
		return 0;
	}
    s1=s;
    reverse(s1.begin(),s1.end());
    if(s1[0]=='0')
    {
        for(int i=0;i<s1.length();i++)
            if(s1[i]!='0')
			{
				s1[i]=char(int(s1[i])-1);
				s1[0]='1';
				break;
			}
    }
    cout<<s1<<" "<<s;
    return 0;
}
