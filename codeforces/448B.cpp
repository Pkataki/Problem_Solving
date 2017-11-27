#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;

int cnt[30];

char s[N], t[N];

int main(){
scanf("%s%s",s,t);
    int n = strlen(s);
    int m = strlen(t);
    
    
    bool sau = false;
    for(int i = 0 , j = 0; i < n; ++i)
    {
        if(j < m && s[i] == t[j]) 
        	++j;
        if(j == m) 
        		sau = true;
    }
    
    for(int i = 0; i < n; ++i)
    		cnt[s[i]-'a']++;
    for(int i = 0; i < m; ++i)
    		cnt[t[i]-'a']--;
    
    bool sar = true;
    bool all = true;
    
    for(int i = 0; i < 26; ++i)
    {
        sar &= cnt[i]==0;
        all &= cnt[i]>=0;
    }
    
    if(sau) 
    	cout << "automaton\n" ;
    
    else if(sar) 
    	cout<<"array\n";
    
    else if(all) 
    	cout<<"both\n"; 
    else 
    	cout<<"need tree\n";    
    return 0;
}