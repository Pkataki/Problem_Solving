#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000007;

string s;
int pi[MAX]; char p[MAX], p2[MAX], T;
void compute_prefix_function(int m){
    int k = pi[0] = -1;
    for (int i = 1; i < m; i++) {
        while (k >= 0 && s[i] != s[k+1])
            k = pi[k];
        if (s[i] == s[k+1]) k++;
        pi[i] = k;
    }
}
int main()
{
	cin >> s;
	compute_prefix_function(s.size());
	int ans = pi[s.size()-1];
	if(ans == -1)
	{
		cout << "Just a legend\n";
		return 0;
	}
	for(int i = 1; i < s.size()-1; i++)
	{
		
		if(ans == pi[i])
		{
			cout << s.substr(0,ans+1) << '\n';
			return 0;
		}
	}
	ans = pi[ans];
	if(ans == -1)
		cout << "Just a legend\n";
	else
		cout << s.substr(0,ans+1) << '\n';

	return 0;
}
