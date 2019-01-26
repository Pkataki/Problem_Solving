
vector<int> v;
#define uint64 unsigned long long
uint64 poww[30005], L[2][30005];
 
void powwB()
{
    poww[0] = 1ULL;
    for(int i = 1; i < 30002; i++) poww[i] = poww[i-1]*33;
    char c = 'a';
    for(int i = 0 ; i < 26; i++){ v.push_back(c-'a'); c++; }
    random_shuffle (v.begin(),v.end());
}
string str;
const uint64 C = 5381ULL;
int n;
void Lcalc(int a)
{
    L[0] = 0;
    for(int i = 0 ; i < n ; i++) L[i+1] = [i] * 33 + v[str[i]-'a'];    	
}
 
uint64 calc_hash(int a, int b, int dir){
    return (L[b+1] - L[a] * poww[b-a+1]);
}

