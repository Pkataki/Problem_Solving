#include<bits/stdc++.h>
using namespace std;

bool prime(int k) 
{
    if (k == 1) {
        return false;
    }
    for (int i = 2; i * i <= k; ++i) {
        if (k % i == 0) {
            return false;
        }
    }
    return true;
}
int cnt[30];
int main()
{
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		cnt[s[i] - 'a']++;
	}
	vector<pair<int,int> >v;
	for(int i = 0; i < 26 ; i++)
	{
		if(cnt[i])
			v.push_back({cnt[i], i});
	}
	sort(v.begin(),v.end());
	int ans = s.size() - 1;

	for(int i = 2; i <= s.size(); i++)
		if(prime(i) && 2*i > s.size())
			ans--;

	if(ans > v.back().first)
	{
		cout << "NO\n";
		return 0;
	}
	vector<char>a;

	for(int i = 0; i < v.size()-1; i++)
	{
		for(int j = 0; j < v[i].first; j++)
		{
			a.push_back( v[i].second + 'a');
		}
	}
	//cout << "**  " << a.size() << " ==> " << ans << endl;
	for(int i = 0; i < v.back().first - ans; i++)
		a.push_back(v.back().second + 'a');

	string ans1 = "";
	//cout << "**  " << a.size() << "\n\n";
	for (int i = 1; i <= s.size(); ++i) 
	{
        if (i == 1 || (prime(i) && 2 * i > s.size())) 
        {
            ans1 += a.back();
            a.pop_back();
        } 
        else 
        {
            ans1 += v.back().second + 'a';
        }
    }
    cout << "YES\n" << ans1 << '\n';
	return 0;
}