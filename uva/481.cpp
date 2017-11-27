#include<bits/stdc++.h>
using namespace std;
void print(const vector<int> &seq, const vector<int> &path, int pos)
{
    if(pos == -1)
        return;
    print(seq, path, path[pos]);
    cout << seq[pos] << endl;
}
int main()
{
	vector<int>seq;
	int n;
	while(cin >> n)
		seq.push_back(n);
	
	vector<int>l(seq.size());
	vector<int>l_id(seq.size());
	vector<int>path(seq.size());
	
	int pos;
	int lis_count = 0;
	int l_end = 0;
	for(int i = 0; i < seq.size(); i++)
	{
		pos = lower_bound(l.begin(),l.begin()+lis_count,seq[i]) - l.begin();
		l[pos] = seq[i];
		l_id[pos] = i;

		path[i] = pos ? l_id[pos-1] : -1;

		if(pos == lis_count)
		{
			lis_count++;
			l_end = i;
		}
	}
	cout << lis_count << "\n-\n";
	print(seq,path,l_end);

	return 0;
}
