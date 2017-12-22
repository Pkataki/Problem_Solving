#include<bits/stdc++.h>
using namespace std;
 
#pragma comment(linker, "/STACK:106777216")
 
void ASS(bool b)
{
    if (!b)
    {
        throw 42;
        ++*(int*)0;
    }
}
 
#define FOR(i, x) for (int i = 0; i < (int)(x); ++i)
#define RFOR(i, x) for (int i = (int)(x) - 1; i >= 0; --i)
#define CL(x) memset(x, 0, sizeof(x))
#define CLX(x, y) memset(x, y, sizeof(x))
 
typedef vector<int> vi;
typedef long long LL;
 
struct node {
    int val;
    int terminal;
 
    int parent;
    int fail;
 
    int firstChildren;
    int brother;
 
    int next; // for hashes table
};
 
const int HS = 1 << 19;
 
int ht[HS];
 
int sz = 1;
node aho[1 << 18];
 
int hashes(int parent, int val) {
    return (parent * 3731 + (parent >> 8) + val) & (HS - 1);
}
 
int find(int parent, int val) 
{
    for (int t = ht[hashes(parent, val)]; t != -1; t = aho[t].next)
        if (aho[t].parent == parent && aho[t].val == val)
            return t;
    return -1;
}
 
int add(int parent, int val) {
    int x = sz++;
    aho[x].parent = parent;
    aho[x].val = val;
 
    aho[x].firstChildren = -1;
 
    aho[x].brother = aho[parent].firstChildren;
    aho[parent].firstChildren = x;
 
    int hp = hashes(parent, x);
    aho[x].next = ht[hp];
    ht[hp] = x;
    return x;
}
 
 
void print(int x, string prefix) {
    if (aho[x].firstChildren == -1)
        cout << prefix << endl;
    for (int t = aho[x].firstChildren; t != -1; t = aho[t].brother)
        print(t, prefix + " " + (char)(aho[t].val));
}
 
void addW(string s) {
    int r = 0;
    FOR(i, s.size()) {
        int t = find(r, s[i]);
        if (t != -1)
            r = t;
        else
            r = add(r, s[i]);
    }
}
 
int main() {
    FOR(i, HS)
        ht[i] = -1;
    aho[0].firstChildren = -1;
 
    addW("abracadabra");
    addW("abrablabla");
    addW("abrabra");
    addW("bcd");
 
    print(0, "");
 
    return 0;
}
