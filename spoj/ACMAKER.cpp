#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool>insig;
vector<string>sig;
string abr;
long long dp[160][160][160];
bool can ; 
int n;
long long solve(int pos_abr, int pos_word,int word)
{
	if(pos_abr == abr.size() && word == sig.size())
	{
		can = 1;
		return 1;
	}
	if(pos_abr >= abr.size() || word >= sig.size())
		return 0;
	if(~dp[pos_abr][pos_word][word])
		return dp[pos_abr][pos_word][word];
	
	long long &ans = dp[pos_abr][pos_word][word];

	ans = 0;
	for(int i = pos_word ; i < sig[word].size(); i++)
	{
		int cont = 1;
		while(abr[pos_abr] == sig[word][i])
		{
	//		if(pos_abr+cont < abr.size() && word + 1<=  sig.size() && pos_word+cont < sig[word].size())
	//		{
				
				ans += solve(pos_abr+cont,pos_word+cont,word+1);
				cont++;
	//		}
	//		else
	//			break;
		}
	}
	ans += solve(pos_abr,0,word+1);
	return ans;
}
int main()
{
	while(cin >>  n && n)
	{
		sig.clear();
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
					tmp_abr= s;
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
			can = 0;
			memset(dp,-1,sizeof(dp));
			long long ans = solve(0,0,0);
			//transform(abr.begin(), abr.end(), abr.begin(), ::toupper);			
			if(can)
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

