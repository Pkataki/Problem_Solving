#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool>insig;
vector<string>sig;
string abr;
long long dp[160][160][160][2];
int n;
long long solve(int pos_abr, int pos_word,int word, int take)
{
	if(pos_abr == abr.size() && word == sig.size())
		return 1LL;
	if(pos_abr == abr.size() || word == sig.size())
		return 0LL;
	if (pos_word == sig[word].size()) 
		return 0LL;

	if(~dp[pos_abr][pos_word][word][take])
		return dp[pos_abr][pos_word][word][take];
	
	long long &ans = dp[pos_abr][pos_word][word][take] = 0LL;

	
	if(sig[word][pos_word] == abr[pos_abr])
		ans += solve(pos_abr+1,pos_word+1,word,1) + solve(pos_abr+1,0,word+1,0);
	
	ans += solve(pos_abr,pos_word+1,word,take);
	
	return ans;
}
int main()
{
	while(cin >>  n && n)
	{
		sig.clear();
		insig.clear();
		string data;
		for(int i = 0; i < n; i++)
		{
			cin >> data;
			transform(data.begin(), data.end(), data.begin(), ::tolower);
			insig[data] = 1;
		}
		getchar();
		string tmp_abr;
		while(getline(cin,data))
		{
			if(data == "LAST CASE")
				break;

			string s;
			istringstream iss(data);
			bool f = 0;
			while(iss >> s)
			{
				if(!f)
				{
					tmp_abr = s;
					transform(s.begin(), s.end(), s.begin(), ::tolower);			
					abr = s;	
				}
				else
				{
					transform(s.begin(), s.end(), s.begin(), ::tolower);			
					if(insig.count(s))
						continue;
					sig.push_back(s);
				}
				f = 1;
			}
			memset(dp,-1,sizeof(dp));
			long long ans = solve(0,0,0,0);
		//	transform(abr.begin(), abr.end(), abr.begin(), ::toupper);			
			if(ans)
			{
				cout << tmp_abr << " can be formed in " << ans << " ways\n";
			}
			else
			{
				cout << tmp_abr << " is not a valid abbreviation\n";	
			}
		}
	}
	return 0;
}
